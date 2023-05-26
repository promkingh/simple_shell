#include "shell.h"

/**
 * main - Entry point for simple shell
 * @argc: argument count
 * @argv: pointer to argument array
 *
 * Return: Exit
 */

int main(int argc, char *argv[])
{
	char *buff, **comm;
	int a, ret, status;

	a = ret = 0, status = 1;

	if (argc > 1 || argv[1] != NULL)
		read_file(argv[1], argv);

	signal(SIGINT, handle_sigint);
	/*signal(SIGINT, handle_seg);
	*/

	_prompt();
	while (status)
	{
		a++;

		if (isatty(STDIN_FILENO))
			_prompt();
		buff = _getline();
		if (buff[0] == '\0')
			continue;
		_hist(buff);

		comm = process_comm(buff);
		if (_strcmp(comm[0], "exit") == 0)
			_exi_t(comm, buff, argv, a);
		else if (_strcmp(comm[0], "alias") == 0)
			;
		else if (inspect_built_in(comm) == 0)
		{
			ret = handle_built_in(comm, ret);
			_free_all(comm, buff);
			continue;
		}
		else
			ret = execute_comm(comm, buff, argv, a);

		_free_all(comm, buff);
	}
	return (status);
}


