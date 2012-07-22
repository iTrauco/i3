/*
 * vim:ts=4:sw=4:expandtab
 *
 * i3 - an improved dynamic tiling window manager
 * © 2009-2011 Michael Stapelberg and contributors (see also: LICENSE)
 *
 * log.c: Logging functions.
 *
 */
#ifndef _LOG_H
#define _LOG_H

#include <stdarg.h>
#include <stdbool.h>

/** ##__VA_ARGS__ means: leave out __VA_ARGS__ completely if it is empty, that
   is, delete the preceding comma */
#define LOG(fmt, ...) verboselog(fmt, ##__VA_ARGS__)
#define ELOG(fmt, ...) errorlog("ERROR: " fmt, ##__VA_ARGS__)
#define DLOG(fmt, ...) debuglog("%s:%s:%d - " fmt, __FILE__, __FUNCTION__, __LINE__, ##__VA_ARGS__)

extern char *errorfilename;
extern char *shmlogname;
extern int shmlog_size;

/**
 * Initializes logging by creating an error logfile in /tmp (or
 * XDG_RUNTIME_DIR, see get_process_filename()).
 *
 */
void init_logging(void);

/**
 * Set debug logging.
 *
 */
void set_debug_logging(const bool _debug_logging);

/**
 * Set verbosity of i3. If verbose is set to true, informative messages will
 * be printed to stdout. If verbose is set to false, only errors will be
 * printed.
 *
 */
void set_verbosity(bool _verbose);

/**
 * Logs the given message to stdout while prefixing the current time to it,
 * but only if debug logging was activated.
 *
 */
void debuglog(char *fmt, ...);

/**
 * Logs the given message to stdout while prefixing the current time to it.
 *
 */
void errorlog(char *fmt, ...);

/**
 * Logs the given message to stdout while prefixing the current time to it,
 * but only if verbose mode is activated.
 *
 */
void verboselog(char *fmt, ...);

/**
 * Logs the given message to stdout while prefixing the current time to it.
 * This is to be called by LOG() which includes filename/linenumber
 *
 */
void slog(char *fmt, va_list args);

#endif