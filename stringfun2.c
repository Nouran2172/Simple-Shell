#include "shell.h"

/**
 * _strcpy - copies a string
 * @dst: the destination
 * @sour: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dst, char *sour)
{
	int i = 0;

	if (dst == sour || sour == 0)
		return (dst);
	while (sour[i])
	{
		dst[i] = sour[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

/**
 * _strdup - duplicates a string
 * @s: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *s)
{
	int length = 0;
	char *rt;

	if (s == NULL)
		return (NULL);
	while (*s++)
		length++;
	rt = malloc(sizeof(char) * (length + 1));
	if (!rt)
		return (NULL);
	for (length++; length--;)
		rt[length] = *--s;
	return (rt);
}

/**
 *_puts - prints an input string
 *@s: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *s)
{
	int i = 0;

	if (!s)
		return;
	while (s[i] != '\0')
	{
		_putchar(s[i]);
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
	static char bf[WRITE_BUF_SIZE];

	if (k == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, bf, i);
		i = 0;
	}
	if (k != BUF_FLUSH)
		bf[i++] = k;
	return (1);
}
