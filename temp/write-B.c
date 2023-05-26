#include "shell.h"
/**
 * _perror - print error
 *
 * @argv: program name
 * @comm: command
 * @n: integer argument
 *
 * Return: nothing
 */
void _perror(char *argv[], char **comm, int n)
{
	char *err = _itoa(n);

	PRINT(argv[0]);
	PRINT(" : ");
	PRINT(err);
	PRINT(": ");
	PRINT(comm[0]);
	PRINT(": illegal number");
	PRINT(comm[1]);
	PRINT("\n");
	free(err);
}
/**
 * _printecho - executes the echo command
 *
 * @command: command argument
 *
 * Return: 1 or -1
 */
int _printecho(char **command)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		if (execve("/bin/echo", command, environ) == -1)
		{
			return (-1);
		}
		exit(EXIT_FAILURE);
	}
	else if (child_pid < 0)
	{
		return (-1);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
