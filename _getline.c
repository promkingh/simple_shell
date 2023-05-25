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

/**
 * get_line - read string input from stream or user
 * @buff: buffer to store string
 * @size: buffer size
 * @stream: stream
 *
 * Return: input string
 */
ssize_t get_line(char **buff, size_t *size, FILE *stream)
{
	ssize_t nread;
	int status, a;

	if (*buff == NULL || *size == 0)
	{
		*size = BUFSIZE;
		*buff = malloc(*size);
		if (buff == NULL)
			return (-1);
	}

	status = 1;
	nread = 0;
	while (status)
	{
		a = fgets(stream);
		if (a == EOF)
			break;
		nread++;
		(*buff)[nread] = a;
		if ((size_t)nread == *size)
		{
			*size *= 2;
			*buff = realloc(*buff, *size);
			if (*buff == NULL)
				return (-1);
		}
		if (a == '\n')
			break;
	}
	(*buff)[nread] = '\0';

	return (nread);
}
