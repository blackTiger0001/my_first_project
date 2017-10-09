#ifndef ERROR_FUNCS_H
#define ERROR_FUNCS_H

#include <unistd.h>
#include <sys/errno.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

extern int perror_cust(const char *fmt, ...);
extern int perror_fd(int fd, const char *fmt, ...);
extern int perror_pid(const char *fmt, ...);
extern int perror_usucc(const char *fmt, ...);
extern int perror_fd_unsucc(int fd, const char *fmt, ...);
extern int perror_pid_unsucc(const char *fmt, ...);

#endif
