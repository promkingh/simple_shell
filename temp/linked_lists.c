#include "shell.h"

/**
 * new_node - creates a new node for a linked list
 * @str: string value
 *
 * Return: pointer to the newly created node
 */
static node_t *new_node(char *str)
{
	node_t *new_node;

	new_node = malloc(sizeof(node_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = str;
	new_node->next = NULL;

	return (new_node);
}

/**
 * add_node - adds a new node to the end of the linked list
 * @h: pointer to the head of the linked list
 * @new_node: node to be added to the linked list
 *
 * Return: nothing
 */
static void add_node(node_t **h, node_t new_node)
{
	node_t *current;

	if (*h == NULL)
		*h = new_node;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = new_node;
	}
}

/**
 * print_list - print the contents of the linked list
 * @h: pointer to the head of the linked list
 *
 * Return: nothing
 */

void print_list(node_t *h)
{
	while (h)
	{
		PRINT(h->str);
		PRINT("\n");
		h = h->next;
	}
}

/**
 * free_list - free memory allocated for each node
 * @h: pointer to the head of the linked list
 *
 * Return: nothing
 */
void free_list(node_t *h)
{
	node_t *temp;

	while (h)
	{
		temp = h;
		h = h->next;
		free(temp);
	}
}
