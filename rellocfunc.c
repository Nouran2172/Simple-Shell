#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@p1: the pointer to the memory area
 *@p2: the byte to fill *s with
 *@n: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *p1, char p2, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		p1[i] = p2;
	return (p1);
}

/**
 * ffree - frees a string of strings
 * @str2: string of strings
 */
void ffree(char **str2)
{
	char **p1 = str2;

	if (!str2)
		return;
	while (*str2)
		free(*str2++);
	free(p1);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr1: pointer to previous malloc'ated block
 * @OLD_size: byte size of previous block
 * @NEW_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr1, unsigned int OLD_size, unsigned int NEW_size)
{
	char *po;

	if (!ptr1)
		return (malloc(NEW_size));
	if (!NEW_size)
		return (free(ptr1), NULL);
	if (NEW_size == OLD_size)
		return (ptr1);

	po = malloc(NEW_size);
	if (!po)
		return (NULL);

	OLD_size = OLD_size < NEW_size ? OLD_size : NEW_size;
	while (OLD_size--)
		po[OLD_size] = ((char *)ptr1)[OLD_size];
	free(ptr1);
	return (po);
}
