BASENAME  = blastcorps
VERSION  := us.v11

VERSIONS  := us.v10 us.v11 jp eu
ifeq ($(filter $(VERSION),$(VERSIONS)),)
$(error Unknown VERSION '$(VERSION)'; expected one of $(VERSIONS))
endif

BUILD_DIR = build
ASM_DIRS  = asm
BIN_DIRS  = assets

TOOLS_DIR := tools

S_FILES   = $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s))

# Every segment the ROM link uses is built into ASSET_DIR by tools/assets.py:
# the assets from their editable files under assets/ (PNGs, YAML, ctl/tbl,
# inflated gzip members), the rest (boot, init, the code modules) copied
# from assets/.  splat's linker script lists them.
ASSET_DIR = $(BUILD_DIR)/assets
LD_BINS  := $(shell grep -o 'build/assets/[A-Za-z0-9_.]*\.bin\.o' $(BASENAME).$(VERSION).ld 2>/dev/null)
O_FILES  := $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file).o) $(LD_BINS)
ASSET_SRCS = $(shell find assets/ -type f 2>/dev/null)

BLASTCORP_EXTRACTED := blastcorps/init.$(VERSION).bin blastcorps/hd_code.$(VERSION).bin blastcorps/hd_front_end.$(VERSION).bin

TARGET = $(BUILD_DIR)/$(BASENAME).$(VERSION)
# splat's script, with the segments from hd_code_text on placed by the size
# of the compressed modules in assets/ (tools/rom_syms.py).  For the
# original modules that is where the config has them.
SPLAT_LD_SCRIPT = $(BASENAME).$(VERSION).ld
LD_SCRIPT = $(BUILD_DIR)/$(BASENAME).$(VERSION).ld

# SHIFT=1: the modules in assets/ came from a shifted stage-2 build (see
# blastcorps/Makefile), so the ROM is not sha1-checked.  The assets move too:
# ASSET_SHIFT_PAD bytes go before every 16-aligned asset (tools/assets.py).
SHIFT ?= 0
ifneq ($(SHIFT),0)
ASSET_SHIFT_PAD ?= 0x10
else
ASSET_SHIFT_PAD := 0
endif

CROSS = mips-linux-gnu-
AS = $(CROSS)as
CPP = cpp
LD = $(CROSS)ld
OBJDUMP = $(CROSS)objdump
OBJCOPY = $(CROSS)objcopy
PYTHON = python3
GZIP = gzip

OBJCOPYFLAGS = -O binary

ASFLAGS = -EB -mtune=vr4300 -march=vr4300 -mabi=32 -I include

LDFLAGS = -T $(LD_SCRIPT) -Map $(TARGET).map --no-check-sections

### Optimisation Overrides

### Targets

default: all

all: dirs $(TARGET).z64 verify

dirs:
	$(foreach dir,$(SRC_DIRS) $(ASM_DIRS) $(BIN_DIRS),$(shell mkdir -p $(BUILD_DIR)/$(dir)))

# asm/ and assets/ hold one version at a time, so leftovers from a previous
# VERSION would quietly be linked into this one.  Refuse to build on a tree
# that was last used for something else.
stamp:
	@if [ -f .version ] && [ "$$(cat .version)" != "$(VERSION)" ]; then \
		echo "error: tree holds $$(cat .version) output; run 'make clean' first" >&2; \
		exit 1; \
	fi
	@echo $(VERSION) > .version

check: .baserom.$(VERSION).ok

verify: $(TARGET).z64
ifeq ($(SHIFT),0)
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $(TARGET).z64" | sha1sum --check
else
	@$(PYTHON) $(TOOLS_DIR)/n64crc.py $(TARGET).z64 --check
	@echo "$(TARGET).z64: shifted build, not sha1-checked"
endif

extract: check stamp assets/layout.yaml

# the ROM's assets rebuilt from assets/ (see ASSET_DIR above)
assets: dirs $(ASSET_DIR)/.stamp

clean:
	rm -rf asm
	rm -rf assets
	rm -rf build
	rm -f *auto.txt
	rm -f *.ld
	rm -f .version
	rm -rf $(BLASTCORP_EXTRACTED)

decompress: $(BLASTCORP_EXTRACTED)

### Recipes

# decompression
assets/%.$(VERSION).ext: assets/%.$(VERSION).bin
	$(GZIP) -d -S ".bin" $< -c > $@

blastcorps/hd_code.$(VERSION).bin: assets/hd_code_text.$(VERSION).ext assets/hd_code_data.$(VERSION).ext
	cat assets/hd_code_text.$(VERSION).ext assets/hd_code_data.$(VERSION).ext > $@

blastcorps/hd_front_end.$(VERSION).bin: assets/hd_front_end_text.$(VERSION).ext assets/hd_front_end_data.$(VERSION).ext
	cat assets/hd_front_end_text.$(VERSION).ext assets/hd_front_end_data.$(VERSION).ext > $@

blastcorps/init.$(VERSION).bin: assets/init.$(VERSION).bin
	cp assets/init.$(VERSION).bin $@

assets/init.$(VERSION).bin:
	$(PYTHON) $(TOOLS_DIR)/splat/split.py $(BASENAME).$(VERSION).yaml

# the editable assets (checked to rebuild to the ROM's bytes)
assets/layout.yaml: | assets/init.$(VERSION).bin
	$(PYTHON) $(TOOLS_DIR)/assets.py extract $(VERSION)

$(BUILD_DIR)/asset_shift.stamp: FORCE
	@mkdir -p $(BUILD_DIR)
	@if [ "$$(cat $@ 2>/dev/null)" != "$(ASSET_SHIFT_PAD)" ]; then echo "$(ASSET_SHIFT_PAD)" > $@; fi

$(ASSET_DIR)/.stamp: $(ASSET_SRCS) $(TOOLS_DIR)/assets.py $(wildcard $(TOOLS_DIR)/assetlib/*) $(BUILD_DIR)/asset_shift.stamp
	@mkdir -p $(ASSET_DIR)
	$(PYTHON) $(TOOLS_DIR)/assets.py build $(VERSION) --out $(ASSET_DIR) --shift $(ASSET_SHIFT_PAD)
	@touch $@

$(ASSET_DIR)/%.bin: $(ASSET_DIR)/.stamp ;

.baserom.$(VERSION).ok: baserom.$(VERSION).z64
	@echo "$$(cat $(BASENAME).$(VERSION).sha1)  $<" | sha1sum --check
	@touch $@

$(LD_SCRIPT): $(SPLAT_LD_SCRIPT) $(ASSET_DIR)/.stamp $(TOOLS_DIR)/rom_syms.py
	@mkdir -p $(BUILD_DIR)
	@$(PYTHON) $(TOOLS_DIR)/rom_syms.py $(VERSION) --out $(BUILD_DIR)/rom.$(VERSION).ld \
		--assets $(ASSET_DIR) --ld-in $(SPLAT_LD_SCRIPT) --ld-out $@

$(TARGET).elf: $(O_FILES) $(LD_SCRIPT)
	@$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.s.o: %.s
	$(AS) $(ASFLAGS) -o $@ $<

$(ASSET_DIR)/%.bin.o: $(ASSET_DIR)/%.bin
	@$(LD) -r -b binary -o $@ $<

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $@

# init is in the 1 MiB the boot code checksums, and a shifted build changes
# the ROM offsets in it.
$(TARGET).z64: $(TARGET).bin
	@cp $< $@
	@$(PYTHON) $(TOOLS_DIR)/n64crc.py $@

### Settings
.SECONDARY:
.PHONY: all assets check clean decompress default dirs extract stamp verify FORCE
SHELL = /bin/bash -e -o pipefail
