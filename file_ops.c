#include "shell.h"

/**
 * file_exit - shell exit case for files
 * @buff: line from file
 * @comm: command
 * @fd: file descriptor
 *
 * Return: nothing
 */

void file_exit(char **comm, char *buff, FILE *fd)
{
	int status, a;

	status = a = 0;
	if (comm[1] == NULL)
	{
		free(buff);
		free(comm);
		close(fd);
		exit(errno);
	}

	while (comm[1][a])
	{
		if (!isdigit(comm[1][a]))
		{
			perror(" illegal numer");
			return;
		}
		a++;
	}
	status = _atoi(comm[1]);

	free(buff);
	free(comm);
	close(fd);
	exit(status);
}

/**
 * access_file - parse, check, fork, wait, execute in a file
 * @buff: line from file
 * @count: error counter
 * @fd: file descriptor
 * @argv: program name
 *
 * Return: nothing
 */
void access_file(char *buff, int count, FILE *fd, char *argv[])
{
	char **comm;
	int status;

	status = 0;
	comm = process_comm(buff);
	if (_strncmp(comm[0], "exit", 4) == 0)
		file_exit(comm, buff, fd);
	else if (inspect_built_in(comm) == 0)
	{
		status = handle_built_in(comm, sta);
		free(buff);
	}
	else
	{
		status = verify_comm(comm, buff, count, argv);
		free(comm);
	}
}

/**
 * read_file - read command from file
 * @filename: filename
 * @argv: program Name
 *
 * Return: -1 or  0
 */

void read_file(char *filename, char *argv[])
{
	char *buff = NULL;
	ssize_t nread;
	FILE *fd;
	size_t len;
	int a;

	len = a = 0;
	fd = open(filename, O_RDONLY);
	if (fd == NULL)
		exit(EXIT_FAILURE);

	nread = get_line(&buff, &len, fd);
	while (nread != -1)
	{
		a++;
		access_file(buff, a, fd, argv);
	}
	if (buff)
		free(buff);
	close(fd);
	exit(0);
}
