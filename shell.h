#ifndef SHELL_H
#define SHELL_H


/*** MACROS ***/
#define BUFSIZE 1024
#define DELIM " \n\t\r\a"


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


/**
 * struct built_in - struct for built-in shell commands
 * @cmd: pointer to array of commands
 * @func: functions to execute
 */
typedef struct built_in
{
	char *cmd;
	int (*func)(char **line, int err);
} buil_t;


/****** PROTOTYPES ******/





#endif /* SHELL_H */
