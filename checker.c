#include "shell.h"

/**
 * inspect_built_in - check builtin
 * @comm: command to check
 *
 * Return: 0 Success, -1 Fail
 */
int inspect_built_in(char **comm)
{
	buil_t ins[] = {
		{"cd", NULL},
		{"history", NULL},
		{NULL, NULL}
	};

	int a = 0;

	if (*comm == NULL)
		return (-1);
	while ((ins + a)->cmd)
	{
		if (_strcmp(comm[0], (ins + a)->cmd) == 0)
			return (0);
		a++;
	}

	return (-1);
}

