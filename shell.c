#include "shell.h"

/**
 * main - Simple Shell
 *
 * Return: 0 success
 */
int main(void)
{
	char **cmd, *buff = NULL;
	int status = 1, a = 0;

	while (status)
	{
		signal(SIGINT, handle_c);

		if (isatty(STDIN_FILENO))
			PRINT("$ ");

		buff = read_comm();
		cmd = comm_parser(buff);
		status = func_getter(cmd, environ);
		free(cmd);
		free(buff);
		a++;
	}

	return (0);
}
