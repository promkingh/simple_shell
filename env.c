#include "shell.h"


/**
 * _env - prints the environment variables
 * @path: environment path
 *
 * Return: 1 sucess
 */
int _env(char **path)
{
	int a, len;
	char *buff = malloc(sizeof(char *) * BUFSIZE);

	a = len = 0;
	while (path[a])
	{
		len = _strlen(path[a]);
		buff = _strdup(path[a]);
		write(STDOUT_FILENO, buff, (len + 1));
		PRINT("\n");
		free(buff);
		a++;
	}

	return (1);
}

/**
 * _getenv - gets the value of an environment variable
 * @env: name of the environment variable
 * @cmd: pointer to user input
 *
 * Return: an integer
 */
char *_getenv(char **env, char *cmd)
{
	char *buff = NULL;
	char *temp = malloc(sizeof(char *) * BUFSIZE);
	char *path = malloc(sizeof(char *) * BUFSIZE);
	int len, a, b, c;

	a = b = c = len = 0;
	while (*env)
	{
		path = _strdup(env[a]);
		buff = strtok(path, "=");
		if (buff != NULL && (_strcmp(buff, cmd)) == 0)
		{
			path = _strdup(env[a]);
			while (buff[++b])
				;
			c = b + 1;
			len = _strlen(path) - c;
			a = 0;
			while (a < len)
			{
				temp[a] = path[c];
				a++;
				c++;
			}
			free(path);
			return (temp);
		}
		free(path);
		a++;
	}

	free(temp);
	free(path);
	return (NULL);
}

/**
 * env_ind - searches and returns the index of variable
 * @env: environment variable
 * @cmd: pointer to user input (argument)
 *
 * Return: index (integer)
 */
int env_ind(char **env, char *cmd)
{
	char *path = malloc(sizeof(char) * BUFSIZE);
	char *token = NULL;
	int a = 0;

	while (*env)
	{
		path = _strdup(env[a]);
		token = strtok(path, "=");

		if ((_strcmp(token, cmd)) == 0 && token != NULL)
		{
			free(path);
			return (a);
		}

		free(path);
		a++;
	}

	return (0);
}

/**
 * _unset_env - unsets the environment
 * @env: environments variable
 * @cmd: pointer to the user input
 *
 * Return: integer
 */
int _unset_env(char **env, char **cmd)
{
	int a = 0;

	if (cmd == NULL || cmd[1] == NULL || cmd[1][0] == '\0')
	{
		errno = EINVAL;
		perror("hsh");
		return (1);
	}

	a = env_ind(env, cmd[1]);
	while (env[a] != NULL)
	{
		env[a] = env[a + 1];
		a++;
	}

	return (1);
}

/**
 * _set_env - sets the environment
 * @env: environment variable
 * @cmd: pointer to user input (argument)
 *
 * Return: integer
 */
int _set_env(char **env, char **cmd)
{
	char *temp = NULL, *s_temp = NULL;
	int a, b, c;

	a = b = c = 0;
	printf("%s\n%s\n", cmd[1], env[0]);

	a = env_ind(env, cmd[1]);
	printf(env[0], "%s\n");
	if (a != 0 && cmd[3] != 0)
	{
		b = _strlen(env[a]);
		_unset_env(env, cmd);

		c = _strlen(cmd[1]) + _strlen(cmd[2]) + 2;

		temp = malloc(BUFSIZE);
		s_temp = malloc(c);

		temp = _strcat(cmd[1], "=");
		s_temp = _strcat(temp, cmd[2]);

		_realloc(env[a], c, _strlen(s_temp));
		env[a] = s_temp;
	}

	return (1);
}


