#include "shell.h"

/**
 * handle_c - handles ctrl + C
 * @sig: signal number
 *
 * Return: nothing
 */
void handle_c(int sig __attribute__((unused)))
{
	signal(SIGINT, handle_c);
	PRINT("\n$ ");
}
