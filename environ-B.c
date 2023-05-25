#include "shell.h"
/**
 * unset_env - deletes environment variables
 *
 * @name: character argument
 *
 * Return: 0 or -1
 */
int unset_env(const char *name)
{
	char **envptr, **tempenv;
	size_t namelen;

	namelen = _strlen(name);

	for (envptr = environ; *envptr != NULL; envptr++)
	{
		if (_strncmp(*envptr, name, namelen) == 0 && (*envptr)[namelen] == '=')
		{
			tempenv = envptr;
			while (*tempenv != NULL)
			{
				*tempenv = *(tempenv + 1);
				tempenv++;
			}

			return (0);
		}
	}

	return (-1);
}
/**
 * get_env - retrieves the value of an environment variable
 *
 * @name: character argument
 *
 * Return: character
 */
char *get_env(char *name)
{
	size_t namelen;
	int x;

	namelen = _strlen(name);
	x = 0;

	while (environ[x] != NULL)
	{
		if (_strncmp(environ[x], name, namelen) == 0 && environ[x][namelen] == '=')
		{
			return (&(environ[x][namelen + 1]));
		}
		x++;
	}

	return (NULL);
}

/**
 * _elemlen - count the length of variables
 * @arr: array of variables
 *
 * Return: length of array
 */
size_t _elemlen(char **arr)
{
	size_t a = 0;

	while (arr[a])
		a++;
	return (a);
}
