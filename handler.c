#include "shell.h"

/**
 * handle_hash_caution - remove everything after # or !
 * @buff: string input
 *
 * Return: Nothing
 */

void handle_hash_caution(char *buff)
{
	int a;

	a = 0;
	while (buff[a])
	{
		if (buff[a] == '#' || buff[a] == '!')
		{
			buff[a] = '\0';
			break;
		}
		a++;
	}
}

/**
 * handle_seg - handles segmentation fault
 * @sig: signal
 *
 * Return: void
 */
void handle_seg(int sig)
{
	printf("Segmentation fault (core dumped)\n");
	exit(1);
}

/**
 * handle_sigint - handles sigint
 * @sig: signal
 *
 * Return: Nothing
 */
void handle_sigint(int sig)
{
	(void)sig;

	printf("\n");
}

/**
 * handle_built_in - handle built-in commands
 * @comm: array of commands
 * @err: error
 *
 * Return: function on success or -1 on failure
 */
int handle_built_in(char **comm, int err)
{
	buil_t sel[] = {
		{"exit", _exit}, {"env", _env}, {"setenv", _setenv},
		{"unsetenv", _unsetenv}, {"cd", _chdir}, {"echo", _chdir},
		{"alias", alias_comm}, {"cd", _chdir}, {"echo", _chdir},
		{NULL, NULL}
	};

	int a = 0;

	while ((sel + a)->cmd)
	{
		if (_strcmp(comm[0], (sel + a)->cmd) == 0)
			return ((sel + a)->func(comm, err));
		a++;
	}

	return (-1);
}

/**
 * handle_alias - handle alias commands
 *
