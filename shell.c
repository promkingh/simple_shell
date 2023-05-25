#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv; pointer to argument array
 *
 * Return: Exit
 */

int main(int argc, char *argv[])
{
	char *in, **comm;
	int a = ret = 0, status = 1;

	if (argc > 1)
		read_file(argv[1], argv);

	signal(SIGINT, handle_sigint);
	signal(SIGINT, handle_seg);

	while (status)
	{
		a++;

		if (isatty(STDIN_FILE))
			_prompt();
		in = _getline();
		if (in[0] == '\0')
			continue;
		_history(in);

hell		comm = process_comm(in);
		if (_strcmp(comm[0], "exit") == 0)
			;


