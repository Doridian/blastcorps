/*
 * BEPass: make a little-endian host keep memory in big-endian (N64) order.
 *
 * Every load and store of a multi-byte scalar (integers, floats, pointers)
 * in the module gets a byte swap, so memory holds exactly the bytes the N64
 * would: data loaded from the ROM, the handwritten engine's view of memory
 * (tools/recomp, which reads RDRAM as big-endian) and the decompiled C all
 * agree without knowing each other's types.  Byte accesses and memcpy are
 * unchanged.  See docs/PORT.md, "Memory model".
 *
 * Initialized globals are emitted by the compiler in host order; the pass
 * records every multi-byte scalar inside their initializers in a table, and
 * a constructor swaps them in place at startup (__bepass_fixup, in the port
 * runtime).  Pointer-valued initializers can only be swapped at run time,
 * which is why this is done for all of them.  Constant globals are made
 * writable for that.
 *
 * Functions that call llvm.va_start are left alone: the va_list and the
 * argument area are host memory written by the caller's native call.
 *
 * It also puts a call to __port_poll() on every loop back edge.  The game
 * busy-waits on counters other threads or interrupts advance (on the N64
 * something preempts it); the port runs its threads one at a time, and
 * the poll is where it lets time pass.  Being an opaque call, it also
 * makes such a loop reload what it waits on, as IDO's code did.
 *
 * The pass runs at the start of the pipeline, before anything can combine
 * or reorder accesses; later passes see explicit bswaps and optimise them
 * (a swapped store to a local followed by a swapped load folds away).
 */
#include "llvm/IR/Constants.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/IR/CFG.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/IntrinsicInst.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/PassManager.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Plugins/PassPlugin.h"
#include "llvm/Transforms/Utils/ModuleUtils.h"

#include <vector>

using namespace llvm;

namespace {

struct BEPass : PassInfoMixin<BEPass> {
    static bool isRequired() { return true; }

    /* integer type of the same size, or null if nothing to swap */
    static IntegerType *swapType(Type *t, const DataLayout &dl, LLVMContext &c) {
        if (t->isIntegerTy()) {
            unsigned bits = t->getIntegerBitWidth();
            if (bits <= 8)
                return nullptr;
            return cast<IntegerType>(t);
        }
        if (t->isFloatTy() || t->isDoubleTy() || t->isPointerTy() || t->isHalfTy())
            return IntegerType::get(c, dl.getTypeSizeInBits(t));
        return nullptr;
    }

    static Value *bswap(IRBuilder<> &b, Value *v) {
        IntegerType *t = cast<IntegerType>(v->getType());
        unsigned bits = t->getBitWidth();
        if (bits % 8)
            report_fatal_error("BEPass: swap of a non-byte-sized integer");
        unsigned wide = (bits + 15) / 16 * 16;
        if (wide == bits)
            return b.CreateUnaryIntrinsic(Intrinsic::bswap, v);
        IntegerType *wt = IntegerType::get(t->getContext(), wide);
        Value *z = b.CreateZExt(v, wt);
        Value *s = b.CreateUnaryIntrinsic(Intrinsic::bswap, z);
        s = b.CreateLShr(s, wide - bits);
        return b.CreateTrunc(s, t);
    }

    static Value *toInt(IRBuilder<> &b, Value *v, IntegerType *it) {
        Type *t = v->getType();
        if (t == it)
            return v;
        if (t->isPointerTy())
            return b.CreatePtrToInt(v, it);
        return b.CreateBitCast(v, it);
    }

    static Value *fromInt(IRBuilder<> &b, Value *v, Type *t) {
        if (v->getType() == t)
            return v;
        if (t->isPointerTy())
            return b.CreateIntToPtr(v, t);
        return b.CreateBitCast(v, t);
    }

    static void fail(Instruction *i, const char *what) {
        std::string s;
        raw_string_ostream os(s);
        os << "BEPass: " << what << " in " << i->getFunction()->getName() << ": " << *i;
        report_fatal_error(StringRef(os.str()));
    }

    bool runOnFunction(Function &f, const DataLayout &dl) {
        for (BasicBlock &bb : f)
            for (Instruction &i : bb)
                if (auto *ii = dyn_cast<IntrinsicInst>(&i))
                    if (ii->getIntrinsicID() == Intrinsic::vastart)
                        return false;
        std::vector<Instruction *> work;
        for (BasicBlock &bb : f)
            for (Instruction &i : bb)
                if (isa<LoadInst>(i) || isa<StoreInst>(i) || isa<AtomicRMWInst>(i) ||
                    isa<AtomicCmpXchgInst>(i) || isa<VAArgInst>(i))
                    work.push_back(&i);
        LLVMContext &c = f.getContext();
        bool changed = false;
        for (Instruction *i : work) {
            if (auto *ld = dyn_cast<LoadInst>(i)) {
                Type *t = ld->getType();
                if (t->isVectorTy() || t->isStructTy() || t->isArrayTy())
                    fail(i, "aggregate or vector load");
                IntegerType *it = swapType(t, dl, c);
                if (!it)
                    continue;
                IRBuilder<> b(ld);
                LoadInst *nl = b.CreateAlignedLoad(it, ld->getPointerOperand(), ld->getAlign(),
                                                   ld->isVolatile());
                nl->setOrdering(ld->getOrdering());
                nl->setSyncScopeID(ld->getSyncScopeID());
                Value *v = fromInt(b, bswap(b, nl), t);
                ld->replaceAllUsesWith(v);
                ld->eraseFromParent();
                changed = true;
            } else if (auto *st = dyn_cast<StoreInst>(i)) {
                Type *t = st->getValueOperand()->getType();
                if (t->isVectorTy() || t->isStructTy() || t->isArrayTy())
                    fail(i, "aggregate or vector store");
                IntegerType *it = swapType(t, dl, c);
                if (!it)
                    continue;
                IRBuilder<> b(st);
                Value *v = bswap(b, toInt(b, st->getValueOperand(), it));
                StoreInst *ns = b.CreateAlignedStore(v, st->getPointerOperand(), st->getAlign(),
                                                     st->isVolatile());
                ns->setOrdering(st->getOrdering());
                ns->setSyncScopeID(st->getSyncScopeID());
                st->eraseFromParent();
                changed = true;
            } else if (isa<VAArgInst>(i)) {
                fail(i, "va_arg outside a va_start function");
            } else {
                Type *t = isa<AtomicRMWInst>(i) ? cast<AtomicRMWInst>(i)->getValOperand()->getType()
                                                : cast<AtomicCmpXchgInst>(i)->getCompareOperand()->getType();
                if (swapType(t, dl, c))
                    fail(i, "atomic access");
            }
        }
        return changed;
    }

    /* (offset, size) of each multi-byte scalar inside an initializer */
    static void collect(Constant *k, uint64_t off, const DataLayout &dl,
                        std::vector<std::pair<uint64_t, unsigned>> &out) {
        Type *t = k->getType();
        if (isa<ConstantAggregateZero>(k) || isa<UndefValue>(k))
            return;
        if (auto *cds = dyn_cast<ConstantDataSequential>(k)) {
            Type *et = cds->getElementType();
            unsigned es = dl.getTypeAllocSize(et);
            unsigned sz = dl.getTypeStoreSize(et);
            if (sz <= 1)
                return;
            for (unsigned n = 0; n < cds->getNumElements(); n++)
                out.push_back({off + (uint64_t)n * es, sz});
            return;
        }
        if (auto *ca = dyn_cast<ConstantArray>(k)) {
            uint64_t es = dl.getTypeAllocSize(ca->getType()->getElementType());
            for (unsigned n = 0; n < ca->getNumOperands(); n++)
                collect(ca->getOperand(n), off + n * es, dl, out);
            return;
        }
        if (auto *cs = dyn_cast<ConstantStruct>(k)) {
            const StructLayout *sl = dl.getStructLayout(cs->getType());
            for (unsigned n = 0; n < cs->getNumOperands(); n++)
                collect(cs->getOperand(n), off + sl->getElementOffset(n), dl, out);
            return;
        }
        if (auto *cv = dyn_cast<ConstantVector>(k)) {
            (void)cv;
            report_fatal_error("BEPass: vector initializer");
        }
        if (t->isIntegerTy() || t->isFloatingPointTy() || t->isPointerTy()) {
            unsigned sz = dl.getTypeStoreSize(t);
            if (sz > 1)
                out.push_back({off, sz});
            return;
        }
        report_fatal_error("BEPass: unhandled initializer");
    }

    void fixGlobals(Module &m, const DataLayout &dl) {
        LLVMContext &c = m.getContext();
        Type *i32 = Type::getInt32Ty(c);
        Type *i8 = Type::getInt8Ty(c);
        PointerType *ptr = PointerType::getUnqual(c);
        StructType *ent = StructType::get(c, {ptr, i32, i32});
        std::vector<Constant *> table;
        std::vector<GlobalVariable *> gvs;
        for (GlobalVariable &g : m.globals())
            gvs.push_back(&g);
        for (GlobalVariable *g : gvs) {
            if (!g->hasInitializer() || g->getName().starts_with("llvm."))
                continue;
            /* no over-alignment (x86 wants arrays 16-aligned): the port
               places the game's variables at their N64 addresses */
            g->setAlignment(dl.getABITypeAlign(g->getValueType()));
            if (g->hasSection() && g->getSection().starts_with("llvm."))
                continue;
            std::vector<std::pair<uint64_t, unsigned>> items;
            collect(g->getInitializer(), 0, dl, items);
            if (items.empty())
                continue;
            g->setConstant(false);
            /* runs of equally sized, contiguous scalars */
            size_t n = 0;
            while (n < items.size()) {
                size_t e = n + 1;
                while (e < items.size() && items[e].second == items[n].second &&
                       items[e].first == items[e - 1].first + items[n].second)
                    e++;
                Constant *addr = ConstantExpr::getGetElementPtr(
                    i8, g, ConstantInt::get(Type::getInt64Ty(c), items[n].first));
                table.push_back(ConstantStruct::get(
                    ent, {addr, ConstantInt::get(i32, e - n), ConstantInt::get(i32, items[n].second)}));
                n = e;
            }
        }
        if (table.empty())
            return;
        ArrayType *at = ArrayType::get(ent, table.size());
        auto *tg = new GlobalVariable(m, at, true, GlobalValue::PrivateLinkage,
                                      ConstantArray::get(at, table), "__bepass_table");
        FunctionType *fixty = FunctionType::get(Type::getVoidTy(c), {ptr, i32}, false);
        FunctionCallee fix = m.getOrInsertFunction("__bepass_fixup", fixty);
        Function *ctor = Function::Create(FunctionType::get(Type::getVoidTy(c), false),
                                          GlobalValue::InternalLinkage, "__bepass_ctor", &m);
        IRBuilder<> b(BasicBlock::Create(c, "entry", ctor));
        b.CreateCall(fix, {tg, ConstantInt::get(i32, table.size())});
        b.CreateRetVoid();
        appendToGlobalCtors(m, ctor, 101);
    }

    static void addPolls(Function &f, FunctionCallee poll) {
        DominatorTree dt(f);
        std::vector<Instruction *> at;
        for (BasicBlock &bb : f) {
            Instruction *t = bb.getTerminator();
            if (!t)
                continue;
            for (BasicBlock *succ : successors(&bb))
                if (dt.dominates(succ, &bb)) {
                    at.push_back(t);
                    break;
                }
        }
        for (Instruction *t : at) {
            IRBuilder<> b(t);
            b.CreateCall(poll);
        }
    }

    PreservedAnalyses run(Module &m, ModuleAnalysisManager &) {
        const DataLayout &dl = m.getDataLayout();
        FunctionCallee poll = m.getOrInsertFunction(
            "__port_poll", FunctionType::get(Type::getVoidTy(m.getContext()), false));
        for (Function &f : m)
            if (!f.isDeclaration()) {
                runOnFunction(f, dl);
                addPolls(f, poll);
            }
        fixGlobals(m, dl);
        return PreservedAnalyses::none();
    }
};

} // namespace

extern "C" LLVM_ATTRIBUTE_WEAK PassPluginLibraryInfo llvmGetPassPluginInfo() {
    return {LLVM_PLUGIN_API_VERSION, "BEPass", "1", [](PassBuilder &pb) {
                pb.registerPipelineStartEPCallback(
                    [](ModulePassManager &mpm, OptimizationLevel) { mpm.addPass(BEPass()); });
            }};
}
