#include "shell.h"

/**
 * create_env - create an array of environmen variables
 * @env: array of environment vars
 *
 * Return: nothing
 */

void create_env(char ***env)
{
	int len, a;

	len = _strlen(environ);
	*env = malloc(sizeof(char *) * (len + 1));
	if (*env == NULL)
	{
		perror("malloc failed");
		free(*env);
		exit(1);
	}

	for (a = 0; a < len; a++)
	{
		(*env)[a] = _strdup(environ[a]);
		if ((*env)[a] == NULL)
		{
			perror("strdup failed");
			exit(1);
		}
	}
	(*env)[a] = NULL;
}
