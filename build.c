#include "shell.h"

/**
 * process_comm - process input from line
 * @in: user input
 *
 * Return: array of processed chars
 */

char ** process_comm(char *in)
{
	char **toks, *tok;
	int a;

	if (in == NULL)
		return (NULL);
	toks = malloc(sieof(char *) * BUFSIZE);
	if (!toks)
	{
		perror("hsh");
		return (NULL);
	}

	tok = _strtok(input, DELIM);
	a = 0;
	while (tok)
	{
		toks[a] = tok;
		tok = _strtok(NULL, DELIM);
		a++;
	}
	toks[a] = NULL;

	return (toks);
}

