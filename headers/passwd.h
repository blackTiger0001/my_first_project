#ifndef PASSWD_H

#define  PASSWD_H

#include <pwd.h>
#include <grp.h>
#include <unistd.h>

extern char *uid_to_unam(uid_t uid);
extern char *unam_to_uid(char *lname);
extern char *gid_to_gnam(gid_t gid);
extern char *gnam_to_gid(char *grnam);
extern char *get_pwshell_unam(char *lname);
extern char *get_pwdir_unam(char *lname);
extern char *get_pwshell_uid(uid_t uid);
extern char *get_pwdir_uid(uid_t uid);

#endif

