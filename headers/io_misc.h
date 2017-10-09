#ifndef IO_MISC_H

#define IO_MISC_H

#include <sys/types.h>     /* open() */
#include <sys/stat.h>      /* open() */
#include <fcntl.h>         /* open(), creat() */
#include <unistd.h>        /* close(), read(), write(), lseek() */

extern int add_fdflag(int fd, int flags);
extern int fd_writeable(int fd);
extern int open_file(const char *path);
extern int stdin_readnl(char *buffer, ssize_t n);
#endif

