/*
 * Headless mupen64plus front-end that plays the ROM with scripted input and
 * saves RDRAM at given frames, for difftest.py --snapshot: real game memory
 * (heap objects, linked lists, pointers that point at things) instead of
 * a random fill.
 *
 *   snapshot ROM OUTDIR FRAME...
 *
 * mupen64plus's configuration and save files (EEPROM) go to OUTDIR too, so
 * the user's own are neither read nor written. *
 * writes OUTDIR/rdram_<frame>.bin (the first 4 MB of RDRAM, big-endian as
 * the N64 sees it).  The program is its own input plugin (exported with
 * -rdynamic): Start and A in turn, which gets through the title, the name
 * entry and the first briefing into Simian Acres, then the stick held
 * forward with A and B pressed now and then.  Video is the rice plugin
 * (SDL_VIDEODRIVER=offscreen keeps it windowless), audio the core's
 * dummy, the RSP rsp-hle.
 */
#define M64P_PLUGIN_PROTOTYPES 1
#define M64P_CORE_PROTOTYPES 1
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <mupen64plus/m64p_types.h>
#include <mupen64plus/m64p_plugin.h>
#include <mupen64plus/m64p_frontend.h>
#include <mupen64plus/m64p_debugger.h>
#include <mupen64plus/m64p_config.h>

static unsigned frame;
static unsigned *frames;
static int nframes, next_frame;
static const char *outdir;
static void *core;

static m64p_error (*pCoreDoCommand)(m64p_command, int, void *);
static void *(*pDebugMemGetPointer)(m64p_dbg_memptr_type);

/* ---- input plugin ------------------------------------------------------ */

EXPORT m64p_error CALL PluginGetVersion(m64p_plugin_type *type, int *ver, int *api,
                                        const char **name, int *caps) {
    if (type) *type = M64PLUGIN_INPUT;
    if (ver) *ver = 0x010000;
    if (api) *api = 0x020100;
    if (name) *name = "blastcorps difftest script";
    if (caps) *caps = 0;
    return M64ERR_SUCCESS;
}
EXPORT m64p_error CALL PluginStartup(m64p_dynlib_handle h, void *c, void (*d)(void *, int, const char *)) {
    (void)h; (void)c; (void)d;
    return M64ERR_SUCCESS;
}
EXPORT m64p_error CALL PluginShutdown(void) { return M64ERR_SUCCESS; }
EXPORT void CALL InitiateControllers(CONTROL_INFO info) {
    info.Controls[0].Present = 1;
    info.Controls[0].RawData = 0;
    info.Controls[0].Plugin = PLUGIN_NONE;
}
static void on_frame(unsigned int index);

/* With no video plugin the core has no frame callback to give, so "frames"
   are controller polls: the game reads controller 1 once a frame. */
EXPORT void CALL GetKeys(int control, BUTTONS *keys) {
    keys->Value = 0;
    if (control != 0)
        return;
    on_frame(frame + 1);
    unsigned f = frame, p = f % 60;
    if (f < 4000) {
        /* menus: Start, then A, every second */
        if (p < 4 && (f / 60) % 2 == 0) keys->START_BUTTON = 1;
        if (p < 4 && (f / 60) % 2 == 1) keys->A_BUTTON = 1;
    } else {
        /* in the level: drive, and press A (get in/out) and B now and then */
        keys->Y_AXIS = 80;
        keys->X_AXIS = (int)((f / 90) % 3) * 40 - 40;
        if (f % 600 < 4) keys->A_BUTTON = 1;
        if (f % 250 < 4) keys->B_BUTTON = 1;
    }
}
EXPORT void CALL ControllerCommand(int c, unsigned char *cmd) { (void)c; (void)cmd; }
EXPORT void CALL ReadController(int c, unsigned char *cmd) { (void)c; (void)cmd; }
EXPORT int CALL RomOpen(void) { return 1; }
EXPORT void CALL RomClosed(void) { }
EXPORT void CALL SDL_KeyDown(int k, int s) { (void)k; (void)s; }
EXPORT void CALL SDL_KeyUp(int k, int s) { (void)k; (void)s; }

/* ---- front-end ----------------------------------------------------------- */

static void on_frame(unsigned int index) {
    frame = index;
    if (getenv("SNAPSHOT_VERBOSE") && index % 100 == 0)
        fprintf(stderr, "frame %u\n", index);
    if (next_frame < nframes && index >= frames[next_frame]) {
        unsigned char *ram = pDebugMemGetPointer ? pDebugMemGetPointer(M64P_DBG_PTR_RDRAM) : NULL;
        if (ram) {
            /* the core keeps RDRAM as native-endian 32-bit words */
            char path[1024];
            snprintf(path, sizeof(path), "%s/rdram_%u.bin", outdir, frames[next_frame]);
            FILE *f = fopen(path, "wb");
            for (unsigned i = 0; i < 0x400000; i += 4) {
                uint32_t w;
                memcpy(&w, ram + i, 4);
                unsigned char be[4] = { w >> 24, w >> 16, w >> 8, w };
                fwrite(be, 1, 4, f);
            }
            fclose(f);
            fprintf(stderr, "snapshot: frame %u -> %s\n", index, path);
            if (getenv("SNAPSHOT_SCREENSHOTS"))
                pCoreDoCommand(M64CMD_TAKE_NEXT_SCREENSHOT, 0, NULL);
        }
        next_frame++;
        if (next_frame == nframes)
            pCoreDoCommand(M64CMD_STOP, 0, NULL);
    }
}

static void debug_cb(void *ctx, int level, const char *msg) {
    (void)ctx;
    if (level <= M64MSG_WARNING || getenv("SNAPSHOT_VERBOSE"))
        fprintf(stderr, "core: %s\n", msg);
}

#define SYM(h, name) dlsym(h, #name)

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "usage: %s ROM OUTDIR FRAME...\n", argv[0]);
        return 1;
    }
    outdir = argv[2];
    mkdir(outdir, 0755);
    nframes = argc - 3;
    frames = calloc(nframes, sizeof(*frames));
    for (int i = 0; i < nframes; i++)
        frames[i] = strtoul(argv[3 + i], NULL, 0);

    core = dlopen("libmupen64plus.so.2", RTLD_NOW | RTLD_GLOBAL);
    if (!core) { fprintf(stderr, "%s\n", dlerror()); return 1; }
    m64p_error (*pCoreStartup)(int, const char *, const char *, void *, ptr_DebugCallback, void *, ptr_StateCallback) = SYM(core, CoreStartup);
    m64p_error (*pCoreAttachPlugin)(m64p_plugin_type, m64p_dynlib_handle) = SYM(core, CoreAttachPlugin);
    pCoreDoCommand = SYM(core, CoreDoCommand);
    pDebugMemGetPointer = SYM(core, DebugMemGetPointer);

    if (pCoreStartup(0x020001, outdir, NULL, NULL, debug_cb, NULL, NULL) != M64ERR_SUCCESS)
        return 1;
    m64p_error (*pConfigOpenSection)(const char *, m64p_handle *) = SYM(core, ConfigOpenSection);
    m64p_error (*pConfigSetParameter)(m64p_handle, const char *, m64p_type, const void *) = SYM(core, ConfigSetParameter);
    m64p_handle sec;
    if (pConfigOpenSection("Core", &sec) == M64ERR_SUCCESS) {
        pConfigSetParameter(sec, "SaveSRAMPath", M64TYPE_STRING, outdir);
        pConfigSetParameter(sec, "SaveStatePath", M64TYPE_STRING, outdir);
        pConfigSetParameter(sec, "ScreenshotPath", M64TYPE_STRING, outdir);
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 1; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    void *rom = malloc(size);
    if (fread(rom, 1, size, f) != (size_t)size) return 1;
    fclose(f);
    if (pCoreDoCommand(M64CMD_ROM_OPEN, (int)size, rom) != M64ERR_SUCCESS) {
        fprintf(stderr, "ROM_OPEN failed\n");
        return 1;
    }

    void *rsp = dlopen("/usr/lib/mupen64plus/mupen64plus-rsp-hle.so", RTLD_NOW);
    if (!rsp) { fprintf(stderr, "%s\n", dlerror()); return 1; }
    m64p_error (*rspStartup)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *)) = SYM(rsp, PluginStartup);
    rspStartup(core, NULL, debug_cb);
    /* a real video plugin: the game waits for its display lists to finish.
       Run with SDL_VIDEODRIVER=offscreen for no window. */
    void *gfx = dlopen("/usr/lib/mupen64plus/mupen64plus-video-rice.so", RTLD_NOW);
    if (!gfx) { fprintf(stderr, "%s\n", dlerror()); return 1; }
    m64p_error (*gfxStartup)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *)) = SYM(gfx, PluginStartup);
    gfxStartup(core, NULL, debug_cb);
    if (pCoreAttachPlugin(M64PLUGIN_GFX, gfx) != M64ERR_SUCCESS)
        fprintf(stderr, "attach gfx failed\n");
    void *self = dlopen(NULL, RTLD_NOW);
    if (pCoreAttachPlugin(M64PLUGIN_INPUT, self) != M64ERR_SUCCESS)
        fprintf(stderr, "attach input failed\n");
    if (pCoreAttachPlugin(M64PLUGIN_RSP, rsp) != M64ERR_SUCCESS)
        fprintf(stderr, "attach rsp failed\n");

    int zero = 0;
    pCoreDoCommand(M64CMD_CORE_STATE_SET, M64CORE_SPEED_LIMITER, &zero);
    pCoreDoCommand(M64CMD_EXECUTE, 0, NULL);
    pCoreDoCommand(M64CMD_ROM_CLOSE, 0, NULL);
    return next_frame == nframes ? 0 : 1;
}
