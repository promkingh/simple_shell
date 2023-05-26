#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string, followed by a new line
 * @str: character pointer
 *
 * Return: void
 */

void _puts(char *str)
{
	unsigned int a;

	a = 0;
	while (str[a])
	{
		_putchar(str[a]);
		a++;
	}
	_putchar('\n');
}

/**
 * _strlen - returns the length of string
 * @str: input string array
 *
 * Return: len
 */

int _strlen(char *str)
{
	unsigned int a, len = 0;

	a = 0;
	while (str[a])
		len++;

	return (len);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: input character c
 *
 * Return: 1 for a letter, 0 for otherwise
 */

int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

/**
 * rev_array - reverses an array
 * @buff: array of arguments
 * @n: length of argument
 *
 * Return: void
 */

void rev_array(char *buff, int n)
{
	int a;
	char temp;

	a = 0;
	while (a < (n / 2))
	{
		temp = buff[a];
		buff[a] = buff[(n - 1) - a];
		buff[(n - 1) - a] = temp;
		a++;
	}
}
