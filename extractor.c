#include "shell.h"

/**
 * read_comm - reads user input from stream
 *
 * Return: nothing
 */
char *read_comm(void)
{
	char *buff = NULL;
	size_t size = 0;
	int nread = 0;

	nread = getline(&buff, &size, stdin);
	if (nread == EOF)
	{
		if ((isatty(STDIN_FILENO)) == 1)
			PRINT("\n");
		exit(0);
	}

	return (buff);
}

/**
 * exec_comm - executes the user command input
 *
 * @cmd: command argument
 * @env: environment variable
 *
 * Return: integer
 */
int exec_comm(char **cmd, char **env)
{
	char *mstrA = malloc(8 * BUFSIZE), *cpath = malloc(8 * BUFSIZE);
	char *mstrB = malloc(sizeof(char) * BUFSIZE), *tpath = NULL;
	pid_t pid, cpid;
	int x = 0;

	if (comm_check(cmd, env, mstrA, cpath, mstrB))
		return (1);
	mstrB = _getenv(env, "PATH");
	tpath = _strcat("/", cmd[0]);
	pid = fork();
	if (pid == 0)
	{	cpath = strtok(mstrB, ":");
		while (cpath)
		{	mstrA = _strcat(cpath, tpath);
			if ((access(mstrA, X_OK)) == 0)
			{	free(tpath);
				x = execve(mstrA, cmd, env);
				if (x == -1)
					perror("hsh");
			}
			free(mstrA);
			cpath = strtok(NULL, ":");
		}
		write(STDERR_FILENO, "hsh", _strlen("hsh") + 1);
		write(2, cmd[0], _strlen(cmd[0]));
		write(2, ": No such file or directory\n", 28);
		exit(EXIT_SUCCESS);
	}
	else if (pid < 0)
		perror("hsh");
	else
	{
		do {	cpid = waitpid(pid, &x, WUNTRACED);
			if (cpid == -1)
				perror("hsh");
		} while (!WIFSIGNALED(x) && !WIFEXITED(x));
	}
	free(tpath), free(mstrA), free(cpath), free(mstrB);
	return (1);
}
/**
 * func_getter - handles the function used for command execution
 *
 * @cmd: command argument
 * @env: environment variable argument
 *
 * Return: integer
 */
int func_getter(char **cmd, char **env)
{
	int x = 0;
	char *builtin[6] = {"exit", "cd", "env", "unsetenv", "setenv", NULL};

	if (cmd[0] == NULL)
		return (1);

	while (builtin[x] != NULL)
	{
		if (_strcmp(builtin[x], cmd[0]) == 0)
		{
			break;
		}
		x++;
	}

	switch (x)
	{
		case 0:
			if (cmd[1] == NULL)
				shell_exit(cmd);
			else
				exit_1(cmd);
			break;
		case 1:
			_chdir(cmd);
			break;
		case 2:
			_env(env);
			break;
		case 3:
			_unset_env(env, cmd);
			break;
		case 4:
			_set_env(env, cmd);
			break;
		default:
			return (exec_comm(cmd, env));
	}

	return (x);
}

