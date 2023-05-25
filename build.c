#include "shell.h"

/**
 * process_comm - process input from line
 * @buff: user input
 *
 * Return: array of processed chars
 */

char **process_comm(char *buff)
{
	char **toks, *tok;
	int a;

	if (buff == NULL)
		return (NULL);
	toks = malloc(sizeof(char *) * BUFSIZE);
	if (!toks)
	{
		perror("hsh");
		return (NULL);
	}

	tok = _strtok(buff, DELIM);
	a = 0;
	while (tok)
	{
		toks[a] = tok;
		tok = _strtok(NULL, DELIM);
		a++;
	}
	toks[a] = NULL;

	return (toks);
}

/**
 * execute_comm - Excute Simple Shell Command (Fork,Wait,Excute)
 * @comm: command
 * @buff: user input
 * @count: execution count
 * @argv: program name
 *
 * Return: 0 Command Excuted, or 1 or -1 for fail
 */
int execute_comm(char **comm, char *buff, char **argv, int count)
{
	pid_t pid;
	int status;
	char *delim = "./", *delm = "/";

	if (*comm == NULL)
		return (-1);

	pid = fork();
	if (pid == -1)
	{
		perror("Fork Error");
		return (-1);
	}
	if (pid == 0)
	{
		if (_strncmp(*comm, delim, 2) != 0 && _strncmp(*comm, delm, 1) != 0)
			_path(comm);
		if (execve(*comm, comm, environ) == -1)
		{
			disp_error(comm[0], count, argv);
			free(buff);
			free(comm);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);

	return (0);
}

/**
 * _build - build command
 * @tok: string
 * @value: directory containing command
 *
 * Return: built command or NULL
 */
char *_build(char *tok, char *value)
{
	char *comm;
	size_t len;

	len = _strlen(tok);
	comm = malloc(len);
	if (comm == NULL)
		return (NULL);
	_memset(comm, 0, len);

	comm = _strcat(comm, value);
	comm = _strcat(comm, "/");
	comm = _strcat(comm, tok);

	return (comm);
}

/**
 * _path - search in $path for executable command
 * @comm: command
 *
 * Return: 0 success, 1 failure
 */
int _path(char **comm)
{
	struct stat buf;
	char *path = _getenv("PATH"), *comm_path;
	char *value = _strtok(path, ":");

	while (value)
	{
		comm_path = _build(*comm, value);
		if (stat(comm_path, &buf) == 0)
		{
			*comm = _strdup(comm_path);
			free(comm_path);
			free(path);
			return (0);
		}
		free(comm_path);
		value = _strtok(NULL, ":");
	}
	free(path);

	return (1);
}
