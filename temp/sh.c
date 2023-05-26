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
	char *buff, **com;
	int a, ret, status;
