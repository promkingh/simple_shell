#include "shell.h"

/**
 * handle_hash_caution - remove everything after # or !
 * @buff: string input
 *
 * Return: Nothing
 */

void handle_hash_caution(char *buff)
{
	int a;

	a = 0;
	while (buff[a])
	{
		if (buff[a] == '#' || buff[a] == '!')
		{
			buff[a] = '\0';
			break;
		}
		a++;
	}
}

/**
 * handle_seg - handles segmentation fault
 * @sig: signal
 *
 * Return: void
 */
void handle_seg(int sig)
{
	printf("Segmentation fault (core dumped)\n");
	exit(1);
}

/**
 * handle_sigint - handles sigint
 * @sig: signal
 *
 * Return: Nothing
 */
void handle_sigint(int sig)
{
	(void)sig;

	printf("\n");
}
