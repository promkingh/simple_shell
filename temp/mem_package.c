#include "shell.h"

/**
 * _malloc - aloocates memory using malloc
 * @b: number of bytes to allocate
 * Return: pointer to allocated memory or exits with value 98 on NULL
 */
void *_malloc(unsigned int b)
{
	void *mal;

	mal = malloc(b);

	if (mal == NULL)
		exit(98);
	return (mal);
}
/**
 * _memcpy - copies the content of src to dest
 * @dest: destination buffer
 * @src: source buffer
 * @n: number of bytes to copy
 * Return: dest.
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
/**
 * _calloc - allocate memory for an array using malloc
 *
 * @nmemb: number of member elements
 * @size: size of bytes
 *
 * Return: pointer to allocated memory or NULL
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *x;
	char *y;
	unsigned int z;

	if (nmemb == 0 || size == 0)
		return (NULL);

	x = malloc(nmemb * size);

	if (x == NULL)
		return (NULL);

	y = (char *)x;

	for (z = 0; z < (nmemb * size); z++)
		y[z] = 0;

	return (x);
}
/**
 * _realloc - reallocate a memory block
 *
 * @ptr: pointer to memory location
 * @old_size: old memory size
 * @new_size: new memory size
 *
 * Return: pointer or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
		return (malloc(new_size));

	free(ptr);
	ptr = malloc(new_size);

	return (ptr);
}

/**
 * _free_all - free array of char pointers
 * @comm: pointer
 * @buff: buffer array
 *
 * Return: Nothing
 */

void _free_all(char **comm, char *buff)
{
	free(comm);
	free(buff);
	comm = NULL;
	buff = NULL;
}
