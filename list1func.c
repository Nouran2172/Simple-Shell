#include "shell.h"

/**
 * list_len - determines length of linked list
 * @pointer1: pointer to first node
 *
 * Return: size of list
 */
size_t list_len(const list_t *pointer1)
{
	size_t x = 0;

	while (pointer1)
	{
		pointer1 = pointer1->next;
		x++;
	}
	return (x);
}
/**
 * list_to_strings - returns an array of strings of the list->str
 * @head1: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head1)
{
	list_t *node1 = head1;
	size_t i = list_len(head1), j;
	char **strings;
	char *str;

	if (!head1 || !i)
		return (NULL);
	strings = malloc(sizeof(char *) * (i + 1));
	if (!strings)
		return (NULL);
	for (i = 0; node1; node1 = node1->next, i++)
	{
		str = malloc(_strlen(node1->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return (NULL);
		}

		str = _strcpy(str, node1->str);
		strings[i] = str;
	}
	strings[i] = NULL;
	return (strings);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(convert_number(head->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node1: pointer to list head
 * @pre: string to match
 * @k: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node1, char *pre, char k)
{
	char *p1 = NULL;

	while (node1)
	{
		p1 = starts_with(node1->str, pre);
		if (p1 && ((k == -1) || (*p1 == k)))
			return (node1);
		node1 = node1->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head1: pointer to list head
 * @node1: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head1, list_t *node1)
{
	size_t i = 0;

	while (head1)
	{
		if (head1 == node1)
			return (i);
		head1 = head1->next;
		i++;
	}
	return (-1);
}
