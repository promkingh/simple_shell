#include "shell.h"
/**
 * _strtok - splits a string into a series of token using a character argument
 * @str: string argument
 * @delim: delimiter character argument
 *
 * Return: string
 */
char *_strtok(char *str, const char *delim)
{
	static char *tok;
	char *ts;

	if (str != NULL)
	{
		tok = str;
	}
	else
	{
		if (tok == NULL || *tok == '\0')
		{
			return (NULL);
		}
	}

	ts = tok;
	while (*tok != '\0')
	{
		if (*tok == *delim)
		{
			*tok = '\0';
			tok++;
			return (ts);
		}
		tok++;
	}

	return (ts);
}
