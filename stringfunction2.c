#include "shell.h"
#include <stdlib.h>

/**
 * _strcpy - copies a string
 * @dst: the destination
 * @sour: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dst, const char *sour)
{
	int i = 0;

	if (dst == sour || sour == NULL)
		return (dst);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
	return (NULL);

	for (int i = 0; i <= length; i++)
	{
		rt[i] = str[i];
	}

	return (rt);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @k: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char k)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}

	if (k != BUF_FLUSH)
		buf[i++] = k;
	return (1);
}
