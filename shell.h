#ifndef SHELL_H
#define SHELL_H


/*** MACROS ***/
#define BUFSIZE 1024
#define DELIM " \n\t\r\a"
#define PRINT(s) (write(STDOUT_FILENO, s, _strlen(s)))

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

/*** MAIN ***/

/*** WRITE ***/
void _prompt();
void disp_error(char *in, int count, char *argv[]);

/*** HANDLERS ***/
void handle_hash_caution(char *buff);
void handle_seg(int sig);
void handle_sigint(int sig);

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

/*** MEMORY PROTOTYPES ***/
void *malloc_checked(unsigned int b);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif /* SHELL_H */
