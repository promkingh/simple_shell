#include "shell.h"

/**
 * _perror - print error
 * @argv: program name
 * @comm: command
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
