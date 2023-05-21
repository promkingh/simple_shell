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
 * _isalpha - checks for alphabetic character
 *
 * @c: input character c
 *
 * Return: 1 for a letter, 0 for otherwise
 */
int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * _strlen - count string characters
 * @s: input array
 * Return: len
 */
int _strlen(char *s)
{
	int i, len;

	len = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	return (len);
}
/**
 * _strcpy - copy string from source to destination
 * @dest: destination to copy to
 * @src: where to copy from
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; src[i] == '\0'; i++)
		dest[i] = '\0';
	return (dest);
}
/**
 * _strncpy - Copyn number of characters from src to dest
 * @dest: destination array
 * @src: source array
 * @n: position to stop copying
 * Return: Char des
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
