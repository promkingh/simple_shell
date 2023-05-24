#include "shell.h"

/**
 * _getline - read string input from stream or user
 *
 * Return: input string
 */

char *getline(void)
{
	ssize_t rea_d;
	int a;
	char ch, *buff;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == NULL)
	{
		return (NULL);
		free(buff);
	}
	ch = a = 0;

	while (ch != EOF && c != '\n')
	{
		rea_d = read(STDIN_FILENO, &c, 1);
		if (rea_d = -1)
		{

