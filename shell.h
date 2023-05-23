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

/*** STRING PROTOTYPES ***/
int _putchar(char c);
int _isalpha(int c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncpy(char *dest, char *src, int n);
void _puts(char *str);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strdup(char *str);
int _atoi(char *s);
int _strcmp(char *s1, char *s2);
void array_rev(char *arr, int n);
int _strncmp(const char *s1, const char *s2, size_t n);
int intlen(int num);
char *_itoa(unsigned int n);
char *_strtok(char *str, const char *delim);


#endif /* SHELL_H */
