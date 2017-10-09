#ifndef STAT_H

#define STAT_H

#include <sys/types.h>       /* stat() */
#include <sys/stat.h>        /* stat() */
#include <fcntl.h>
#include <unistd.h>          /* stat() */
#include <utime.h>   
#include <sys/uio.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <uapi/linux/fs.h>

#include <pwd.h>
#include <grp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/errno.h>


struct get_stat{
    enum { PATH=1, LINK=2, FD=3} type;
    union { char *path;  int fd;} refrence;
};

extern int getstat(struct get_stat , struct stat *);
extern char *gettype_str(struct stat *);
extern char *getowner_str(struct stat *);
extern char *getgroup_str(struct stat *);
extern char *getutime_str(time_t *);
extern char *getutime_strlong(time_t  *);
extern char *permtostr(mode_t mode, int flags);
extern mode_t strtoperm(char *permstr);
extern int printstat(struct get_stat, int);

#endif

