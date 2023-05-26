#include "shell.h"
/**
 * _strip_spaces - finds and remove white spaces from a string
 *
 * @str: string to be stripped
 *
 * Return: nothing
 */
void _strip_spaces(char *str)
{
	int x, y, senlen, spcount;

	if (str == NULL)
		return;

	x = 0;
	y = 0;
	senlen = _strlen(str);
	spcount = 0;

	while (str[x] == ' ' || str[x] == '\t')
		x++;

	while (x < senlen)
	{
		if (str[x] != ' ' && str[x] != '\t')
		{
			str[y] = str[x];
			y++;
			x++;
			spcount = 0;
		}
		else if (spcount == 0)
		{
			str[y] = ' ';
			y++;
			x++;
			spcount++;
		}
		else
		{
			x++;
		}
	}

	if (y > 0 && str[y - 1] == ' ')
		y--;
	str[y] = '\0';
}
