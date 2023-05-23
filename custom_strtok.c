#include "shell.h"
/**
 * _strtok - splits a string into a series of token using a character argument
 *
 * @str: string argument
 * @delim: delimiter character argument
 *
 * Return: string
 */
char *_strtok(char *str, const char *delim)
{
	static char *trk;
	char *ts;

	if (str != NULL)
	{
		trk = str;
	}
	else
	{
		if (trk == NULL || *trk == '\0')
		{
			return (NULL);
		}
	}

	ts = trk;
	while (*trk != '\0')
	{
		if (*trk == *delim)
		{
			*trk = '\0';
			trk++;
			return (ts);
		}
		trk++;
	}

	return (ts);
}
