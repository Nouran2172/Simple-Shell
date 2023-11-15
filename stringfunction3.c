#include "shell.h"

/**
 * _strncpy - copies a string
 * @dst: the destination string to be copied to
 * @sour: the source string
 * @n: the amount of characters to be copied
 * Return: the concatenated string
 */
char *_strncpy(char *dst,char *sour, int n)
{
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++)
    {
        dst[i] = sour[i];
    }

    for (; i < n; i++)
    {
        dst[i] = '\0';
    }

    return dst;
}

/**
 * _strncat - concatenates two strings
 * @dst: the first string
 * @sour: the second string
 * @n: the amount of bytes to be maximally used
 * Return: the concatenated string
 */
char *_strncat(char *dst, char *src, int n)
{
    int i, j;

    for (i = 0; dst[i] != '\0'; i++)
        ;

    for (j = 0; j < n && sour[j] != '\0'; j++, i++)
    {
        dst[i] = sour[j];
    }

    dst[i] = '\0';

    return dst;
}

/**
 * _strchr - locates a character in a string
 * @str: the string to be parsed
 * @k: the character to look for
 * Return: (s) a pointer to the memory area s
 */
char *_strchr(const char *str, char k)
{
    do
    {
        if (*str == k)
            return (char *)str;
    } while (*str++ != '\0');

    return NULL;
}

