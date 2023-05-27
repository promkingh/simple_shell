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

/****** PROTOTYPES ******/

/*** MAIN ***/


/*** BUILTIN PROTOTYPES ***/
int exit_1(char **cmd);
int _chdir(char **cmd);

/*** HANDLER PROTOTYPES ***/
void handle_c(int sig __attribute__((unused)));

/*** STRING PROTOTYPES ***/
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
int _isalpha(int c);
int _isdigit(int c);
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
int atoi_close(char *str);
unsigned int _strcspn(char *strA, char *strB);
char *_itoa(unsigned int n);
char *_strtok(char *str, const char *delim);

/*** MEMORY PROTOTYPE ***/
char *_memcpy(char *dest, char *src, unsigned int n);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*** PARSER PROTOTYPES ***/
int path_getter(char **cmd, char **env);
void shell_exit(char **cmd);
int comm_check(char **cmd, char **env, char *mst, char *cpath, char *tpath);
char **comm_parser(char *cmd);

/*** EXTRACTOR PROTOTYPES ***/
char *read_comm(void);
int exec_comm(char **cmd, char **env);
int func_getter(char **cmd, char **env);

/*** ENV PROTOTYPES ***/
int _env(char **path);
char *_getenv(char **env, char *cmd);
int env_ind(char **env, char *cmd);
int _unset_env(char **env, char **cmd);
int _set_env(char **env, char **cmd);


#endif /* SHELL_H */
