#include "Shell.h"

/**
 * _prompt - display shell prompt
 */
void _prompt(void)
{
	PRINT("promise&toheeb$ ");
}

/**
 * disp_error - display Error bassed
 * @buff: user input
 * @count: shell loop
 * @argv: prog name
 *
 * Return: Nothing
 */
void disp_error(char *buff, int count, char *argv[])
{
	char *err;

	PRINT(argv[0]);
	PRINT(": ");

	err = _itoa(count);
	PRINT(err);
	free(err);

	PRINT(buff);
	PRINT(": not found\n");
}

/**
 * write_unsig_int - print unsigned integer
 * @n: unsigned integer input
 *
 * Return: nothing
 */
void write_unsig_int(unsigned int n)
{
	unsigned int num = n;

	if ((num / 10) > 0)
		write_unsig_int(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * int_to_unsig - print int in unsigned int
 * @n: integer
 *
 * Return: nothing
 */

void int_to_unsig(int n)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		num = -num;
	}
	if ((num / 10) > 0)
		int_to_unsig(num / 10);
	_putchar((num % 10) + '0');
}

/**
 * write_alias - print aliases
 * @alias: alias name
 *
 * Return: nothing
 */
void write_alias(alias_t alias)
{
	PRINT("alias  ");
	PRINT(alias->alias_comm);
	PRINT("='");
	PRINT(alias->alias_comm);
	PRINT("'");
	PRINT("\n");
}
