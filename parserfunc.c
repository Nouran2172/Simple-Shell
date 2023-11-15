#include "shell.h"

/**
 * is_cmd - determines if a file is an executable command
 * @inf: the info struct
 * @path1: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *inf, char *path1)
{
	struct stat str;

	(void)inf;
	if (!path1 || stat(path1, &str))
		return (0);

	if (str.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicates characters
 * @pathstr1: the PATH string
 * @head: starting index
 * @stop1: stopping index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr1, int head, int stop1)
{
	static char bf[1024];
	int i = 0, j = 0;

	for (j = 0, i = head; i < stop1; i++)
		if (pathstr1[i] != ':')
			bf[j++] = pathstr1[i];
	bf[j] = 0;
	return (bf);
}

/**
 * find_path - finds this cmd in the PATH string
 * @inf: the info struct
 * @pathstr1: the PATH string
 * @cmd: the cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *inf, char *pathstr1, char *cmd)
{
	int i = 0, j = 0;
	char *path1;

	if (!pathstr1)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(inf, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr1[i] || pathstr1[i] == ':')
		{
			path1 = dup_chars(pathstr1, j, i);
			if (!*path1)
				_strcat(path1, cmd);
			else
			{
				_strcat(path1, "/");
				_strcat(path1, cmd);
			}
			if (is_cmd(inf, path1))
				return (path1);
			if (!pathstr1[i])
				break;
			j = i;
		}
		i++;
	}
	return (NULL);
}
