#include "shell.h"

/**
 * exit_1 - prints a message on exit
 * @cmd: pointer to the user input
 *
 * Return: int
 */
int exit_1(char **cmd)
{
	int ret;

	ret = atoi_close(cmd[1]);

	if (ret != -1)
		exit(ret);
	else
	{
		perror("hsh");
		return (0);
	}
}

/**
 * _chdir - change directory
 * @cmd: pointer to the user input
 *
 * Return: integer
 */
int _chdir(char **cmd)
{
	char *home = _getenv(environ, "HOME");
	char *dir = NULL;
	int n_a;

	if (!cmd[1])
		dir = home;
	else
	{
		if (_strcmp(cmd[1], "-"))
			dir = _getenv(environ, "OLDPWD");
		else if (_strcmp(cmd[1], "~"))
			dir = home;
		else
			dir = cmd[1];
	}

	n_a = access(dir, F_OK | R_OK);
	if (n_a == 0 || dir == home)
		chdir(dir);
	else
		perror("hsh");

	return (0);
}
