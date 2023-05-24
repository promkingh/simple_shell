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

/*** HANDLERS ***/


/*** STRING PROTOTYPES ***/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
int _isalpha(int c);
void rev_array(char *buff, int n);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *str1, char *str2);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char *_strchr(char *str, char c);
int intlen(int num);
int _atoi(char *str);
char *_itoa(unsigned int n);
char *_strtok(char *str, const char *delim);


#endif /* SHELL_H */
