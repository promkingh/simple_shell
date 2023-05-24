#include "shell.h"

/**
 * _getline - read string input from stream or user
 *
 * Return: input string
 */

char *_getline(void)
{
	ssize_t rea_d;
	int a;
	char ch, *buff;

	buff = malloc(sizeof(char) * BUFSIZE);
	if (buff == NULL)
	{	return (NULL);
		free(buff);
	}
	ch = a = 0;
	while (ch != EOF && c != '\n')
	{	rea_d = read(STDIN_FILENO, &c, 1);
		if (rea_d == -1)
		{	free(buff);
			perror("Error: ");
		}
		else if (rea_d == 0)
		{	free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[a] = ch;
		if (buff[0] == \n'')
		{	free(buff);
			return ("\0");
		}
		if ((a + 1) >= BUFSIZE)
		{
			buff = _realloc(buff, a + 1);
			if (buff == NULL)
			{
				free(buff);
				return (NULL);
			}
		}
		a++;
	}
	buff[a - 1] = '\0';
	handle_hash_caution(buff);

	return (buff);
}
