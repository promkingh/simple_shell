#include "shell.h"

/**
 * _strdup - duplicates a string
 * @str: pointer to the string to duplicate
 *
 * Return: pointer to the duplicated string or NULL
 */

char *_strdup(char *str)
{
	unsigned int a, len = 0;
	char *ns;

	if (str == NULL)
		return (NULL);
	len = _strlen(str);

	ns = malloc(sizeof(char) * (len + 1));
	if (ns == NULL)
		return (NULL);

	a = 0;
	while (a < len)
	{
		ns[a] = str[a];
		a++;
	}

	return (ns);
}

/**
 * _strchr - search for a character
 * @str: input string
 * @c: character being searched for
 *
 * Return: pointer to string or NULL
 */
char *_strchr(char *str, char c)
{
	int a;

	a = 0;
	while (str[a] && str[a] != c)
		str++;
	if (str[a] == c)
		return ((char *)str);
	else
		return (NULL);
}

/**
 * _intlen - length of an integer
 * @num: integer argument
 * Return: integer
 */
int _intlen(int num)
{
	int len = 0;

	while (num != 0)
	{
		num /= 10;
		len++;
	}

	return (len);
}

/**
 * _atoi - Convert a string to an integer.
 * @str: The string to convert
 *
 * Return: A integer
 */
int _atoi(char *str)
{
	int c = 0;
	int min = 1, isi = 0;
	unsigned int ni = 0;

	while (str[c])
	{
		if (str[c] == 45)
			min *= -1;
		while (str[c] > 47 && str[c] < 58)
		{
			isi = 1;
			ni = (ni * 10) + (str[c] - '0');
			c++;
		}
		if (isi == 1)
			break;
		c++;
	}
	ni += min;

	return (ni);
}

/**
 * _itoa - converts an integer to a character
 * @n: integer argument
 *
 * Return: character pointer
 */
char *_itoa(unsigned int n)
{
	int len, a;
	char *str;

	len = 0;
	len = _intlen(n);

	str = malloc(len + 1);
	if (!str)
		return (NULL);
	*str = '\0';

	a = 0;
	while (n / 10)
	{
		str[a] = (n % 10) + '0';
		n /= 10;
		a++;
	}

	str[a] = (n % 10) + '0';
	rev_array(str, len);
	str[a + 1] = '\0';

	return (str);
}
