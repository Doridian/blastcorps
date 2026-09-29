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

#endif
