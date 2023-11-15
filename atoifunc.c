#include "shell.h"

/**
 * interactive - returns true if shell is in interactive mode
 * @info: struct address
 *
 * Return: 1 if in interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimiter
 * @k: the char to check
 * @delim: the delimiter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char k, const char *delim)
{
    while (*delim)
        if (*delim++ == k)
            return (1);
    return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @k: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _isalpha(int k)
{
    return ((k >= 'a' && c <= 'z') || (k >= 'A' && k <= 'Z'));
}

/**
 * _atoi - converts a string to an integer
 * @w: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */
int _atoi(const char *w)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; w[i] != '\0' && flag != 2; i++)
    {
        if (w[i] == '-')
            sign *= -1;

        if (w[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (w[i] - '0');
        }
        else if (flag == 1)
            flag = 2;
    }

    if (sign == -1)
        output = -result;
    else
        output = result;

    return (output);
}

