/*
 * Force-included into every N64-side file (the game's C and port/src).
 *
 * The game defines or calls functions under libc/libm names (libultra's
 * sinf, cosf, bcopy, bzero, sprintf, memcpy, strlen, strchr).  Its own
 * versions are built for big-endian memory and would interpose on the
 * host's for SDL and the GL driver, so they get other names here.
 */
#ifndef PORT_GAME_H
#define PORT_GAME_H

#define sinf n64_sinf
#define cosf n64_cosf
#define bcopy n64_bcopy
#define bzero n64_bzero
#define sprintf n64_sprintf
#define memcpy n64_memcpy
#define strlen n64_strlen
#define strchr n64_strchr

#endif
