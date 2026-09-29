/* Host-side internals (port/host). */
#ifndef HOST_H
#define HOST_H

#include "port.h"
#include "recomp.h"

/* threads.c */
int host_run_one(void);             /* run the best runnable thread; 0 if none */
void host_threads_dump(void);
recomp_context *port_ctx(void);

void host_charge(uint64_t ns);

/* video.c */
extern int host_max_frames;
extern const char *host_screenshot_prefix;
extern int host_headless;
extern const char *host_save_path;
void host_video_init(void);
void host_video_frame(void);
void host_video_shutdown(void);

/* the renderer: 0 software (gfx.c), 1 OpenGL (gfx_gl.c); -1 until chosen
   (OpenGL with a window, software headless) */
extern int host_renderer;
extern int gfx_filter;              /* GFX_FILTER_* (gfx.h) */
extern int gfx_gl_scale;            /* internal resolution factor, 0: the window's */
struct SDL_Window;
unsigned gfx_gl_window_flags(void);
int gfx_gl_init(struct SDL_Window *win);
void gfx_gl_present(uint32_t vi_fb, int vi_width, const char *screenshot);

#endif
