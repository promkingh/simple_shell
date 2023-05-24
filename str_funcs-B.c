#include "shell.h"

/**
 * _strcpy - copy string from source to destination
 * @dest: destination to copy to
 * @src: where to copy from
 *
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[i]; a++)
		dest[a] = src[a];
	for (; src[a]; a++)
		dest[a] = '\0';
	return (dest);
}

/**
 * _strncpy - Copyn number of characters from src to dest
 * @dest: destination to copy to
 * @src: where to copy from
 * @n: number of characters to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int a;

	for (a = 0; a < n && src[a]; a++)
		dest[a] = src[a];
	for (; a < n; a++)
		dest[a] = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @str1: string one
 * @str2: string two
 *
 * Return: integer
 */

int _strcmp(char *str1, char *str2)
{
	int a;

	for (a = 0; str1[a] || str2[a]; a++)
	{
		if (str1[a] != str2[a])
			return (str1[a] - str2[a]);
	}

	return (0);
}

/**
 * _strncmp - compares the number of characters between two string arguments
 * @str1: string argument
 * @str2: string argument
 * @n: integer argument
 *
 * Return: 1 or 0 or -1
 */

int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t a;

	if (str1 == NULL)
		return (-1);
	for (a = 0; a < n && str2[a]; a++)
	{
		if (str1[a] != str2[a])
			return (1);
	}

	return (0);
}

/**
 * *_strcat - Concatenates two strings
 *
 * @dest: input pointer string
 * @src: input pointer string
 *
 * Return: pointer to the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a]; a++)
		;
	for (b = 0; src[b]; b++)
		dest[a + b] = src[b];
	dest[a + b] = '\0';

	return (dest);
}
