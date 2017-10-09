#include <stdio.h>
#include <stdarg.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

struct file_obj { char name[256], mode[3]; FILE *file;};

int open_files(int n, ...);
extern void err_print(void);
extern void open_file(struct file_obj *obj);
