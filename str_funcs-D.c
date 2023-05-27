#include "shell.h"
/**
 * _isdigit - Checks if an input is is digit
 *
 * @c: the character to print
 *
 * Return: 1 (true) or 0 (false)
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

/**
 * atoi_close - exits the atoi function
 *
 * @str: string argument
 *
 * Return: integer
 */
int atoi_close(char *str)
{
	int x, y, pid_max;

	x = 0;
	y = 0;
	pid_max = 4194304;

	if (str[y] == '-')
	{
		return (1);
	}

	while (str[y])
	{
		if (_isdigit(str[y]) == 1)
		{
			x = x * 10 + str[y] - '0';
		}
		else
		{
			return (1);
		}
		y++;
	}

	if (x > pid_max)
	{
		return (1);
	}
	else
	{
	return (x);
	}
}
/**
 * _strcspn - calculates the number of characters before the
 *		first character of strB is found in strA
 *
 * @strA: string argument
 * @strB: string argument
 *
 * Return: integer
 */
unsigned int _strcspn(char *strA, char *strB)
{
	unsigned int x;

	for (x = 0; strA[x]; x++)
	{
		if (_strchr(strB, strA[x]))
			return (x);
	}
	return (x);
}
