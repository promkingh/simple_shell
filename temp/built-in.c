#include "shell.h"

/**
 * _exi_t - shell exit status
 * @comm: process command
 * @buff: input
 * @argv: program name
 * @count: count
 *
 * Return: nothing;
 */
void _exi_t(char **comm, char *buff, char *argv[], int count)
{
	int a, status;

	if (comm[1] == NULL)
	{
		free(buff);
		free(comm);
		exit(EXIT_SUCCESS);
	}

	a = 0;
	while (comm[1][a])
	{
		if (_isalpha(comm[1][a++] != 0))
		{
			_perror(argv, comm, count);
			break;
		}
		else
		{
			status = _atoi(comm[1]);
			free(buff);
			free(comm);
			exit(status);
		}
	}
}

/**
 * _chdir - change directory
 * @comm: command
 *
 * Return: nothing
 */

int _chdir(char **comm, int err)
{
	char *home = getenv("HOME");
	char *oldpwd = getenv("OLDPWD");
	char *pwd = getenv("PWD");
	char cwd[BUFSIZE];

	(void)err;
	if (comm[1] == NULL)
	{
		if (chdir(home) == -1)
		{
			perror("cd");
			return (-1);
		}
		setenv("OLDPWD", pwd, 1);
		setenv("pwd", oldpwd, 1);
	}
	else if (_strcmp(comm[1], "-") == 0)
	{
		if (oldpwd)
		{
			if (chdir(oldpwd) == -1)
			{
				perror("cd");
				return (-1);
			}
			setenv("OLDPWD", pwd, 1);
			setenv("pwd", oldpwd, 1);
		}
	}
	else
	{
		if (chdir(comm[1]) == -1)
		{
			perror("cd");
			return (-1);
		}
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", pwd, 1);
		setenv("pwd", cwd, 1);
	}

	return (0);
}
