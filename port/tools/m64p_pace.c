/*
 * Headless mupen64plus front-end that records how the game paces itself and
 * what it plays, as the reference for the port's timing and audio
 * (docs/PORT.md, "Timing" and "Audio").
 *
 *   m64p_pace ROM OUTDIR SCRIPT POLLS
 *
 * SCRIPT is "attract" (no input: the Rare logo, the title and the attract
 * mode) or "play" (PORT_AUTOSTART=2's input: Start/A taps through the title
 * and the name entry into Simian Acres, then the stick held forward).  It stops after
 * POLLS controller reads.  It writes
 *
 *   OUTDIR/pace.csv   one line per controller read (the game reads the pad
 *                     once a frame): poll, retraces (the scheduler's count,
 *                     D_803156C4), game frames (D_80358064), the mode
 *                     (D_80364A90), and the audio written so far (samples)
 *   OUTDIR/audio.wav  everything the game gave the AI, at the AI's rate
 *
 * The program is its own input plugin and audio plugin (both exported with
 * -rdynamic; PluginGetVersion answers for whichever is being attached).
 * Video is rice (SDL_VIDEODRIVER=offscreen), the RSP rsp-hle, which runs the
 * audio lists itself: the samples come from its audio HLE.
 *
 *   cc -O1 -Wall -rdynamic -o m64p_pace port/tools/m64p_pace.c -ldl
 */
#define M64P_PLUGIN_PROTOTYPES 1
#define M64P_CORE_PROTOTYPES 1
#include <dlfcn.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <mupen64plus/m64p_types.h>
#include <mupen64plus/m64p_plugin.h>
#include <mupen64plus/m64p_frontend.h>
#include <mupen64plus/m64p_debugger.h>
#include <mupen64plus/m64p_config.h>

static unsigned polls, max_polls;
static int play;
static const char *outdir;
static FILE *csv, *wav;
static uint64_t wav_samples;
static unsigned ai_rate = 22050;
static m64p_plugin_type attaching;
static AUDIO_INFO ai;
static unsigned char *rdram;

static m64p_error (*pCoreDoCommand)(m64p_command, int, void *);
static void *(*pDebugMemGetPointer)(m64p_dbg_memptr_type);

/* the core keeps RDRAM as native-endian words */
static uint32_t rd32(uint32_t a) {
    uint32_t w;
    memcpy(&w, rdram + (a & 0x3FFFFC), 4);
    return w;
}

EXPORT m64p_error CALL PluginGetVersion(m64p_plugin_type *type, int *ver, int *api,
                                        const char **name, int *caps) {
    if (type) *type = attaching;
    if (ver) *ver = 0x010000;
    if (api) *api = attaching == M64PLUGIN_AUDIO ? 0x020000 : 0x020100;
    if (name) *name = "blastcorps pacing probe";
    if (caps) *caps = 0;
    return M64ERR_SUCCESS;
}
EXPORT m64p_error CALL PluginStartup(m64p_dynlib_handle h, void *c, void (*d)(void *, int, const char *)) {
    (void)h; (void)c; (void)d;
    return M64ERR_SUCCESS;
}
EXPORT m64p_error CALL PluginShutdown(void) { return M64ERR_SUCCESS; }
EXPORT int CALL RomOpen(void) { return 1; }
EXPORT void CALL RomClosed(void) { }

/* ---- input ---------------------------------------------------------------- */

EXPORT void CALL InitiateControllers(CONTROL_INFO info) {
    info.Controls[0].Present = 1;
    info.Controls[0].RawData = 0;
    info.Controls[0].Plugin = PLUGIN_NONE;
}

EXPORT void CALL GetKeys(int control, BUTTONS *keys) {
    keys->Value = 0;
    if (control != 0)
        return;
    polls++;
    if (!rdram && pDebugMemGetPointer)
        rdram = pDebugMemGetPointer(M64P_DBG_PTR_RDRAM);
    if (rdram)
        fprintf(csv, "%u,%u,%u,%08X%08X,%llu\n", polls, rd32(0x803156C4), rd32(0x80358064),
                rd32(0x80364A90), rd32(0x80364A94), (unsigned long long)wav_samples);
    if (play && rdram) {
        /* PORT_AUTOSTART=2: Start and A by the scheduler's retrace count,
           then, once in the level, the stick held forward */
        static int in_level;
        if (rd32(0x80364A90) == 0 && rd32(0x80364A94) == 4)
            in_level = 1;
        unsigned f = rd32(0x803156C4) % 120;
        if (in_level)
            keys->Y_AXIS = 80;
        else if (f < 4)
            keys->START_BUTTON = 1;
        else if (f >= 60 && f < 64)
            keys->A_BUTTON = 1;
    }
    if (polls >= max_polls)
        pCoreDoCommand(M64CMD_STOP, 0, NULL);
}
EXPORT void CALL ControllerCommand(int c, unsigned char *cmd) { (void)c; (void)cmd; }
EXPORT void CALL ReadController(int c, unsigned char *cmd) { (void)c; (void)cmd; }
EXPORT void CALL SDL_KeyDown(int k, int s) { (void)k; (void)s; }
EXPORT void CALL SDL_KeyUp(int k, int s) { (void)k; (void)s; }

/* ---- audio ------------------------------------------------------------------ */

static void wav_header(void) {
    uint32_t data = (uint32_t)(wav_samples * 4);
    uint8_t h[44];
    memcpy(h, "RIFF", 4);
    uint32_t v = 36 + data; memcpy(h + 4, &v, 4);
    memcpy(h + 8, "WAVEfmt ", 8);
    v = 16; memcpy(h + 16, &v, 4);
    uint16_t s = 1; memcpy(h + 20, &s, 2);
    s = 2; memcpy(h + 22, &s, 2);
    v = ai_rate; memcpy(h + 24, &v, 4);
    v = ai_rate * 4; memcpy(h + 28, &v, 4);
    s = 4; memcpy(h + 32, &s, 2);
    s = 16; memcpy(h + 34, &s, 2);
    memcpy(h + 36, "data", 4);
    memcpy(h + 40, &data, 4);
    fseek(wav, 0, SEEK_SET);
    fwrite(h, 1, 44, wav);
    fseek(wav, 0, SEEK_END);
}

EXPORT void CALL AiDacrateChanged(int system) {
    unsigned clock = system == SYSTEM_PAL ? 49656530 : system == SYSTEM_MPAL ? 48628316 : 48681812;
    ai_rate = clock / (*ai.AI_DACRATE_REG + 1);
    fprintf(stderr, "ai: dacrate %u -> %u Hz\n", *ai.AI_DACRATE_REG, ai_rate);
}
EXPORT void CALL AiLenChanged(void) {
    uint32_t addr = *ai.AI_DRAM_ADDR_REG & 0xFFFFF8, len = *ai.AI_LEN_REG & 0x3FFF8;
    for (uint32_t i = 0; i < len; i += 4) {
        uint32_t w;
        memcpy(&w, ai.RDRAM + ((addr + i) & 0x7FFFFC), 4);
        int16_t lr[2] = { (int16_t)(w >> 16), (int16_t)w };
        fwrite(lr, 2, 2, wav);
    }
    wav_samples += len / 4;
}
EXPORT int CALL InitiateAudio(AUDIO_INFO info) { ai = info; return 1; }
EXPORT void CALL ProcessAList(void) { }
EXPORT void CALL SetSpeedFactor(int p) { (void)p; }
EXPORT void CALL VolumeUp(void) { }
EXPORT void CALL VolumeDown(void) { }
EXPORT int CALL VolumeGetLevel(void) { return 100; }
EXPORT void CALL VolumeSetLevel(int l) { (void)l; }
EXPORT void CALL VolumeMute(void) { }
EXPORT const char *CALL VolumeGetString(void) { return "100%"; }

/* ---- front-end ---------------------------------------------------------------- */

static void debug_cb(void *ctx, int level, const char *msg) {
    (void)ctx;
    if (level <= M64MSG_WARNING)
        fprintf(stderr, "core: %s\n", msg);
}

#define SYM(h, name) dlsym(h, #name)

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "usage: %s ROM OUTDIR attract|play POLLS\n", argv[0]);
        return 1;
    }
    outdir = argv[2];
    mkdir(outdir, 0755);
    play = !strcmp(argv[3], "play");
    max_polls = (unsigned)strtoul(argv[4], NULL, 0);
    char path[1024];
    snprintf(path, sizeof path, "%s/pace.csv", outdir);
    csv = fopen(path, "w");
    fprintf(csv, "poll,retraces,frames,mode,audio_samples\n");
    snprintf(path, sizeof path, "%s/audio.wav", outdir);
    wav = fopen(path, "wb+");
    wav_header();

    void *core = dlopen("libmupen64plus.so.2", RTLD_NOW | RTLD_GLOBAL);
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
    }

    FILE *f = fopen(argv[1], "rb");
    if (!f) { perror(argv[1]); return 1; }
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    void *rom = malloc(size);
    if (fread(rom, 1, size, f) != (size_t)size) return 1;
    fclose(f);
    if (pCoreDoCommand(M64CMD_ROM_OPEN, (int)size, rom) != M64ERR_SUCCESS)
        return 1;

    void *rsp = dlopen("/usr/lib/mupen64plus/mupen64plus-rsp-hle.so", RTLD_NOW);
    void *gfx = dlopen("/usr/lib/mupen64plus/mupen64plus-video-rice.so", RTLD_NOW);
    if (!rsp || !gfx) { fprintf(stderr, "%s\n", dlerror()); return 1; }
    m64p_error (*startup)(m64p_dynlib_handle, void *, void (*)(void *, int, const char *));
    startup = SYM(rsp, PluginStartup);
    startup(core, NULL, debug_cb);
    startup = SYM(gfx, PluginStartup);
    startup(core, NULL, debug_cb);
    void *self = dlopen(NULL, RTLD_NOW);
    pCoreAttachPlugin(M64PLUGIN_GFX, gfx);
    attaching = M64PLUGIN_AUDIO;
    if (pCoreAttachPlugin(M64PLUGIN_AUDIO, self) != M64ERR_SUCCESS)
        fprintf(stderr, "attach audio failed\n");
    attaching = M64PLUGIN_INPUT;
    if (pCoreAttachPlugin(M64PLUGIN_INPUT, self) != M64ERR_SUCCESS)
        fprintf(stderr, "attach input failed\n");
    pCoreAttachPlugin(M64PLUGIN_RSP, rsp);

    int zero = 0;
    pCoreDoCommand(M64CMD_CORE_STATE_SET, M64CORE_SPEED_LIMITER, &zero);
    pCoreDoCommand(M64CMD_EXECUTE, 0, NULL);
    pCoreDoCommand(M64CMD_ROM_CLOSE, 0, NULL);
    wav_header();
    fclose(wav);
    fclose(csv);
    return 0;
}
