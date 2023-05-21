#include "shell.h"
/**
 * _puts - prints a string, followed by a new line
 *
 * @str: character pointer
 *
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');

}
/**
 * *_strcat - Concatenates two strings
 *
 * @dest: input pointer string
 * @src: input pointer string
 *
 * Return: character pointer
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] !=  '\0'; i++)
	{
	}

	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i + j] = src[j];
	}
	dest[i + j] = '\0';

	return (dest);
}
/**
 * _strchr - search for a character
 * @s: input string
 * @c: character being searched for
 * Return: pointer s or NULL
 */
char *_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		s++;
	if (s[i] == c)
		return ((char *) s);
	else
		return (NULL);
}
/**
 * _strdup - duplicate a string
 * @str: pointer to the tring to duplicate
 * Return: pointer to the duplicated string or NULL
 */
char *_strdup(char *str)
{
	unsigned int i, j, len = 0;
	char *s;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		len++;

	s = malloc((len + 1) * sizeof(char));

	if (s == NULL)
		return (NULL);

	j = 0;

	while (j < len)
	{
		s[j] = str[j];
		j++;
	}

	return (s);
}
/**
 * _atoi - Convert a string to an integer.
 * @s: The pointer to convert
 *
 * Return: A integer
 */
int _atoi(char *s)
{
	int c = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[c])
	{
		if (s[c] == 45)
		{
			min *= -1;
		}

		while (s[c] >= 48 && s[c] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[c] - '0');
			c++;
		}

		if (isi == 1)
		{
			break;
		}

		c++;
	}

	ni *= min;
	return (ni);
}
