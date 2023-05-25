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

/****** STRUCTURES ******/
/**
 * struct built_in - struct for built-in shell commands
 * @cmd: pointer to array of commands
 * @func: functions to execute
 */
typedef struct built_in
{
	char *cmd;
	int (*func)(char **buff, int err);
} buil_t;

/**
 * struct aliases - struct for shell alias
 * @name: name of alias
 * @alias_comm: command for alias
 */
typedef struct aliases
{
	char *name;
	char *alias_comm;
} alias_t;

/**
 * struct Node - singly linked list
 * @str: buffer array
 * @next: pointer to the next node
 */
typedef struct Node
{
	char *str;
	struct Node *next;
} node_t;


/****** PROTOTYPES ******/

/*** MAIN ***/
int main(int argc, char *argv[]);
char *_getline(void);

/*** WRITE ***/
void _prompt(void);
void disp_error(char *in, int count, char *argv[]);
void write_unsig_int(unsigned int n);
void int_to_unsig(int n);
void write_alias(alias_t alias);
void _perror(char *argv[], char **comm, int n);
int _printecho(char **command);


/*** HANDLERS ***/
void handle_hash_caution(char *buff);
void handle_seg(int sig);
void handle_sigint(int sig);
int handle_built_in(char **comm, int err);

/*** FILE OPERATIONS ***/
void file_exit(char **comm, char *buff, FILE *fd);
void access_file(char *buff, int count, FILE *fd, char *argv[]);
void read_file(char *filename, char *argv[]);


/*** BUILD PROTOTYPES ***/
char **process_comm(char *in);

/*** STRIP PROTOTYPES ***/
void _strip_spaces(char *str);




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

/*** LINKED LIST ***/
node_t *new_node(char *str);
void add_node(node_t **h, node_t new_node);
void print_list(node_t *h);
void free_list(node_t *h);

/*** MEMORY PROTOTYPES ***/
void *_malloc(unsigned int b);
char *_memcpy(char *dest, char *src, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void _free_all(char **comm, char *buff);
char *_memset(char *s, char b, unsigned int n);

/*** ENVIRONMENT PROTOTYPES ***/
void create_env(char ***env);
int _env(void);
void add_new_env(node_t **h, const char *name, const char *value);
void updateenv(node_t *h);
int set_env(const char *name, const char *value);
int unsetenv(const char *name);
char *get_env(char *name);
size_t _elemlen(char **arr);
void _freeenv(char **env);

/*** HISTORY PROTOTYPES ***/
int disp_hist(__attribute__((unused))char **command, __attribute__((unused))int execstate);
int fill_hist(char *userinput);


#endif /* SHELL_H */
