#include "shell.h"
/**
 * delim_checker - checks if a character has matches in a string
 *
 * @a: character argument
 * @str: string argument
 *
 * Return: 1 or 0
 */
unsigned int delim_checker(char a, const char *str)
{
	unsigned int x;

	for (x = 0; str[x] != ''\0'; x++)
	{
		if (a == str[x])
		{
			return (1);
		}
	}

	return (0);
}
/**
 * _strtok - splits a string into a series of token using a character argument
 *
 * @str: string argument
 * @delim: character argument
 *
 * Return: string 
 */
char *_strtok(char *str, const char *delim)
{
	unsigned int x;
	static char *sp, *pn;

	if (str != NULL)
	{
		pn = str;
	}

	if (sp == NULL)
	{
		return (NULL);
	}

	sp = pn;

	for (x = 0; sp[x] != '\0'; x++)
	{
		if (delim_checker(sp[x], delim) == 0)
		{
			break;
		}
	}

	if (pn[x] == '\0' || pn[x] == '#')
	{
		pn = NULL;
		return (NULL);
	}

	sp = pn + x;
	pn = sp;

	for (x = 0; pn[x] != '\0'; x++)
	{
		if (delim_checker(pn[x], delim) == 1)
		{
			break;
		}
	}

	if (pn[x] == '\0')
	{
		pn = NULL;
	}
	else
	{
		pn[x] = '\0';
		pn = pn + x + 1;
		if (*pn == '\0')
		{
			pn = NULL;
		}
	}

	return (sp);
}
