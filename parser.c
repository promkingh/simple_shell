#include "shell.h"
/**
 * path_getter - retrieves the path for command execution
 *
 * @cmd: command argument
 * @env: environment variable argument
 *
 * Return: integer
 */
int path_getter(char **cmd, char **env)
{
	int x = 0, y = 0;
	char *delim = "/", *tmp = NULL;
	pid_t pid, cpid;

	tmp = _strdup(cmd[0]);
	if ((access(cmd[0], R_OK | X_OK)) == 0)
	{	pid = fork();
		if (pid == 0)
		{	x = execve(cmd[0], cmd, env);
			if (x == -1)
				perror("hsh");
			exit(EXIT_SUCCESS);
		}
		else if (pid < 0)
			perror("hsh");
		else
		{
			do {
				cpid = waitpid(pid, &x, WUNTRACED);
				if (cpid == -1)
					perror("hsh");
			} while (!WIFSIGNALED(x) && !WIFEXITED(x));
		}
		free(tmp);
		return (1);
	}
	else if (tmp != NULL)
	{
		for (y = 0; tmp[y] != '\0'; y++)
		{
			if (tmp[y] == delim[0])
			{	errno = ENOENT;
				perror("hsh");
				free(tmp);
				return (1);
			}
		}
	}
	free(tmp);
	return (0);
}
/**
 * shell_exit - terminates the shell session
 *
 * @cmd: command argument
 *
 * Return: void
 */
void shell_exit(char **cmd)
{
	free(*cmd);
	free(cmd);
	exit(EXIT_SUCCESS);
}
/**
 * comm_check - checks the user command input
 *
 * @cmd: string argument
 * @env: environment variable argument
 * @mst: string argument
 * @cpath: command path argument
 * @tpath: path argument
 *
 * Return: integer
 */
int comm_check(char **cmd, char **env, char *mst, char *cpath, char *tpath)
{
	if ((path_getter(cmd, env)) == 1)
	{
		return (1);
	}
	if (mst == NULL || cpath == NULL || tpath == NULL)
	{
		shell_exit(NULL);
	}

	return (0);
}
/**
 * comm_parser - processes the command to know the type and its function
 *
 * @cmd: command argument
 *
 * Return: character
 */
char **comm_parser(char *cmd)
{
	int x, cmdbuffer;
	char *userinput, **cmdtokens;

	x = 0;
	cmdbuffer = BUFSIZE;
	userinput = NULL;
	cmdtokens = NULL;

	cmdtokens = malloc(cmdbuffer * sizeof(char *));
	if (!cmdtokens)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}

	userinput = strtok(cmd, DELIM);
	while (userinput != NULL)
	{
		cmdtokens[x] = userinput;
		userinput = strtok(NULL, DELIM);
		x++;
	}

	if (x >= cmdbuffer)
	{
		cmdbuffer += BUFSIZE;
		cmdtokens = _realloc(cmdtokens, BUFSIZE, cmdbuffer * sizeof(char *));

		if (!cmdtokens)
		{
			{
				perror("hsh: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		userinput = strtok(NULL, DELIM);
	}

	cmdtokens[x] = NULL;
	return (cmdtokens);
}
