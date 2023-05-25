#include "shell.h"
/**
 * create_env - create an array of environmen variables
 *
 * @env: array of environment vars
 *
 * Return: nothing
 */
void create_env(char ***env)
{
	int len, a;

	len = _elemlen(environ);
	*env = malloc(sizeof(char *) * (len + 1));
	if (*env == NULL)
	{
		perror("malloc failed");
		free(*env);
		exit(1);
	}

	for (a = 0; a < len; a++)
	{
		(*env)[a] = _strdup(environ[a]);
		if ((*env)[a] == NULL)
		{
			perror("strdup failed");
			exit(1);
		}
	}
	(*env)[a] = NULL;
}
/**
 * _env - prints the environment variables
 *
 * Return: 0
 */
int _env(void)
{
	char **envptr;
	node_t *list_head;

	list_head = NULL;

	for (envptr = environ; *envptr != NULL; envptr++)
	{
		add_node(&list_head, new_node(*envptr));
	}

	print_list(list_head);
	free_list(list_head);

	return (0);
}
/**
 * add_new_env - adds a new environment variable to a linked list
 *
 * @h: linked list argument
 * @name: character argument
 * @value: character argument
 *
 * Return: void
 */
void add_new_env(node_t **h, const char *name, const char *value)
{
	size_t nmlen, valuelen;
	char *newenv;
	node_t *currnode;

	nmlen = _strlen(name);
	valuelen = _strlen(value);
	currnode = *h;
	newenv = malloc(nmlen + valuelen + 2);

	if (newenv == NULL)
	{
		return;
	}

	_memcpy(newenv, (void *)name, nmlen);
	newenv[nmlen] = '=';
	_memcpy(newenv + nmlen + 1, (void *)value, valuelen);
	newenv[nmlen + valuelen + 1] = '\0';

	while (currnode != NULL)
	{
		if (_strncmp(currnode->str, name, nmlen) == 0 && currnode->str[nmlen] == '=')
		{
			free(currnode->str);
			currnode->str = newenv;
			return;
		}
		currnode = currnode->next;
	}

	add_node(h, new_node(newenv));
}
/**
 * update_env - updates the environ variable with variables stored
 *		in a linked list
 * @h: linked list argument
 *
 * Return: void
 */
void update_env(node_t *h)
{
	size_t nodecount, x;
	node_t *currnode;
	char **newenv;

	nodecount = 0;
	currnode = *h;

	while (currnode != NULL)
	{
		nodecount++;
		currnode = currnode->next;
	}

	newenv = (char **)malloc((nodecount + 1) * sizeof(char *));
	if (newenv == NULL)
	{
		return;
	}

	currnode = h;
	for (x = 0; x < nodecount; x++)
	{
		newenv[x] = currnode->str;
		currnode = currnode->next;
	}

	newenv[nodecount] = NULL;
	environ = newenv;
}
/**
 * _setenv - sets environment variables
 *
 * @name: character argument
 * @value: character argument
 *
 * Return: 0 Success
 */
int _setenv(const char *name, const char *value)
{
	char **envptr;
	node_t *list_head;

	list_head = NULL;

	for (envptr = environ; *envptr != NULL; envptr++)
	{
		add_node(&list_head, new_node(*envptr));
	}

	add_new_env(&list_head, name, value);
	updateenv(list_head);
	free_list(list_head);

	return (0);
}
