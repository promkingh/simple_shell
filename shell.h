#ifndef SHELL_H
#define SHELL_H

/*** ENVIRONMENT VARIABLE ***/
extern char **environ;

/*** MACROS ***/
#define BUFSIZE 1024
#define MAX_ARGS 1024
#define DELIM " \n\t\r\a"
#define PRINT(s) (write(STDOUT_FILENO, s, _strlen(s)))
#define MAX_ALIAS 100

/*** Libraries ***/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <linux/limits.h>





#endif /* SHELL_H */
