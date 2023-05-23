#include "shell.h"
/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: integer
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] || s2[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}
/**
 * array_rev - reverses an array
 *
 * @arr: array argument
 * @n: length argument
 *
 * Return: void
 */
void array_rev(char *arr, int n)
{
	int a;
	char phol;

	for (a = 0; a < (n / 2); a++)
	{
		phol = arr[a];
		arr[a] = arr[(n - 1) - a];
		arr[(n - 1) - a] = phol;
	}
}
/**
 * _strncmp - compares the number of characters between two string arguments
 *
 * @s1: string argument
 * @s2: string argument
 * @n: integer argument
 *
 * Return: 1 or 0 or -1
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t a;

	if (s1 == NULL)
		return (-1);
	for (a = 0; a < n && s2[a]; a++)
	{
		if (s1[a] != s2[a])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * intlen - calculates the length of an integer
 * @num: integer argument
 * Return: integer
 */
int intlen(int num)
{
	int numlen;

	numlen = 0;
	while (num != 0)
	{
		num /= 10;
		numlen++;
	}
	return (numlen);
}
/**
 * _itoa - converts an integer to a character
 *
 * @n: integer argument
 *
 * Return: character pointer
 */
char *_itoa(unsigned int n)
{
	char *a;
	int numlen, i;

	numlen = 0;
	i = 0;
	numlen = intlen(n);
	a = malloc(numlen + 1);

	if (!a)
	{
		return (NULL);
	}

	*a = '\0';

	while (n / 10)
	{
		a[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	a[i] = (n % 10) + '0';
	array_rev(a, numlen);
	a[i + 1] = '\0';

	return (a);
}
