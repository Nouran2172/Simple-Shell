#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @x: the string whose length to check
 *
 * Return: integer length of string
 */
size_t _strlen(char *x)
{
    size_t len = 0;

    if (!x)
        return 0;

    while (x[len])
        len++;

    return len;
}

/**
 * _strcmp - performs lexicographic comparison of two strings.
 * @x1: the first string
 * @x2: the second string
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *x1,char *x2)
{
    while (*x1 && (*x1 == *x2))
    {
        x1++;
        x2++;
    }

    return *(unsigned char *)x1 - *(unsigned char *)x2;
}

/**
 * starts_with - checks if needle starts with haystack
 * @stack: string to search
 * @Needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
const char *starts_with(const char *stack, const char *Needle)
{
    while (*Needle)
        if (*Needle++ != *stack++)
            return NULL;

    return stack;
}

/**
 * _strcat - concatenates two strings
 * @dst: the destination buffer
 * @sour: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dst, const char *sour)
{
    char *rt = dst;

    while (*dst)
        dst++;

    while ((*dst++ = *sour++))
        ;

    return rt;
}

