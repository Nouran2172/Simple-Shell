#include "shell.h"

/**
 * get_history_file - gets the history file
 * @inf: parameter struct
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *inf)
{
	char *bf, *dirc;

	dirc = _getenv(inf, "HOME=");
	if (!dirc)
		return (NULL);
	bf = malloc(sizeof(char) * (_strlen(dirc) + _strlen(HIST_FILE) + 2));
	if (!bf)
		return (NULL);
	bf[0] = 0;
	_strcpy(bf, dirc);
	_strcat(bf, "/");
	_strcat(bf, HIST_FILE);
	return (bf);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @inf: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int write_history(info_t *inf)
{
	ssize_t fd;
	char *name = get_history_file(inf);
	list_t *node = NULL;

	if (!name)
		return (-1);

	fd = open(name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(name);
	if (fd == -1)
		return (-1);
	for (node = inf->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}

/**
 * read_history - reads history from file
 * @inf: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *inf)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *name = get_history_file(inf);

	if (!name)
		return (0);

	fd = open(name, O_RDONLY);
	free(name);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	bf = malloc(sizeof(char) * (fsize + 1));
	if (!bf)
		return (0);
	rdlen = read(fd, bf, fsize);
	bf[fsize] = 0;
	if (rdlen <= 0)
		return (free(bf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (bf[i] == '\n')
		{
			bf[i] = 0;
			build_history_list(inf, bf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(inf, bf + last, linecount++);
	free(bf);
	inf->histcount = linecount;
	while (inf->histcount-- >= HIST_MAX)
		delete_node_at_index(&(inf->history), 0);
	renumber_history(inf);
	return (inf->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @inf: Structure containing potential arguments. Used to maintain
 * @bf: buffer
 * @count: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *inf, char *bf, int count)
{
	list_t *node = NULL;

	if (inf->history)
		node = inf->history;
	add_node_end(&node, bf, count);

	if (!inf->history)
		inf->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @inf: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *inf)
{
	list_t *node1 = inf->history;
	int x = 0;

	while (node1)
	{
		node1->num = x++;
		node1 = node1->next;
	}
	return (inf->histcount = x);
}
