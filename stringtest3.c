#include "shell.h"

/**
 **_strncpy - copies a string
 *@dst: the destination string to be copied to
 *@sour: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dst, char *sour, int n)
{
	int i, j;
	char *s = dst;

	i = 0;
	while (sour[i] != '\0' && i < n - 1)
	{
		dst[i] = sour[i];
		i = i + 1;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dst[j] = '\0';
			j = j + 1;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dst: the first string
 *@sour: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dst, char *sour, int n)
{
	int i, j;
	char *s = dst;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i = i + 1;
	while (sour[j] != '\0' && j < n)
	{
		dst[i] = sour[j];
		i = i + 1;
		j = j + 1;
	}
	if (j < n)
		dst[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@str: the string to be parsed
 *@k: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *str, char k)
{
	do {
		if (*str == k)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
