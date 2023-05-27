#include "shell.h"
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
