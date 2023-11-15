#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @x: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *x)
{
	int i = 0;

	if (!x)
		return (0);

	while (*x++)
		i++;
	return (i);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @x1: the first strang
 * @x2: the second strang
 *
 * Return: negative if x1 < x2, positive if x1 > x2, zero if x1 == x2
 */
int _strcmp(char *x1, char *x2)
{
	while (*x1 && *x2)
	{
		if (*x1 != *x2)
			return (*x1 - *x2);
		x1++;
		x2++;
	}
	if (*x1 == *x2)
		return (0);
	else
		return (*x1 < *x2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @stack: string to search
 * @Needle: the substring to find
 *
 * Return: address of next char of stack or NULL
 */
char *starts_with(const char *stack, const char *Needle)
{
	while (*Needle)
		if (*Needle++ != *stack++)
			return (NULL);
	return ((char *)stack);
}

/**
 * _strcat - concatenates two strings
 * @dst: the destination buffer
 * @sour: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dst, char *sour)
{
	char *rt = dst;

	while (*dst)
		dst++;
	while (*sour)
		*dst++ = *sour++;
	*dst = *sour;
	return (rt);
}
