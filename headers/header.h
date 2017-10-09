#ifndef HEADER_H

#define HEADER_H

#define _XOPEN_SOURCE


#include <sys/types.h>     /* open() */
#include <sys/stat.h>      /* open() */
#include <fcntl.h>         /* open(), creat() */
#include <unistd.h>        /* close(), read(), write(), lseek() */
#include <sys/ioctl.h>

#include <netinet/in.h>    /* socket address structures */
#include <arpa/inet.h>     /* inet_pton(), inet_ntop(), htons(), ntohl() */
#include <sys/socket.h>


#include <time.h>
#include <sys/errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdarg.h>

#include "errorfuncs.h"
#include "io_misc.h"

#define EOF_ERROR(x, y) if(x == -1){ perror(y); errno =0;}
#define _exitEOF_ERROR(x, y) if(x == -1){ perror(y); errno =0; _exit(EXIT_FAILURE);}
#define NULL_ERROR(x, y) if(x == NULL){ perror(y); errno =0;}

#endif












