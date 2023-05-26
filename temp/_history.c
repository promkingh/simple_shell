#include "shell.h"
/**
 * disp_hist - displays the history of user input on the
 * simple shell
 *
 * @command: command argument
 * @execstate: state argument
 *
 * Return: 0 or -1
 */
int disp_hist(char **command, int execstate)
{
	char *fn, *cntstr;
	FILE *fd;
	char *linecon = NULL;
	size_t bufflen;
	int linecount;

	(void)command;
	(void)execstate;
	fn = ".shell_history";
	bufflen = 0;
	linecount = 0;
	fd = fopen(fn, "r");

	if (fd == NULL)
	{
		return (-1);
	}

	while ((getline(&linecon, &bufflen, fd)) != -1)
	{
		linecount++;
		cntstr = _itoa(linecount);
		PRINT(cntstr);
		free(cntstr);
		PRINT(" ");
		PRINT(linecon);
	}
	if (linecon)
	{
		free(linecon);
	}
	fclose(fd);
	return (0);
}
/**
 * _hist - writes the history of user input onto a file
 *
 * @userinput: character argument
 *
 * Return: 1 or -1
 */
int _hist(char *userinput)
{
	char *fn;
	int inputlen;
	ssize_t filedesc, filewrite;

	inputlen = 0;
	fn = ".shell_history";

	if (!fn)
	{
		return (-1);
	}

	filedesc = open(fn, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (filedesc < 0)
	{

		return (-1);
	}

	if (userinput)
	{
		while (userinput[inputlen])
		{
			inputlen++;
		}
		filewrite = write(filedesc, userinput, inputlen);
		if (filewrite < 0)
		{
			return (-1);
		}
	}

	return (1);
}
