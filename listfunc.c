#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head1: address of pointer to head node
 * @str1: str field of node
 * @num1: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head1, const char *str1, int num1)
{
	list_t *new_head;

	if (!head1)
		return (NULL);
	NEW_head = malloc(sizeof(list_t));
	if (!NEW_head)
		return (NULL);
	_memset((void *)NEW_head, 0, sizeof(list_t));
	new_head->num1 = num1;
	if (str1)
	{
		NEW_head->str1 = _strdup(str1);
		if (!NEW_head->str1)
		{
			free(NEW_head);
			return (NULL);
		}
	}
	NEW_head->next = *head1;
	*head1 = NEW_head;
	return (NEW_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head1: address of pointer to head node
 * @str1: str field of node
 * @num1: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head1, const char *str1, int num1)
{
	list_t *NEW_node, *node1;

	if (!head1)
		return (NULL);

	node1 = *head1;
	NEW_node = malloc(sizeof(list_t));
	if (!NEW_node)
		return (NULL);
	_memset((void *)NEW_node, 0, sizeof(list_t));
	NEW_node->num1 = num1;
	if (str1)
	{
		NEW_node->str1 = _strdup(str1);
		if (!NEW_node->str1)
		{
			free(NEW_node);
			return (NULL);
		}
	}
	if (node1)
	{
		while (node1->next)
			node1 = node1->next;
		node1->next = NEW_node;
	}
	else
		*head1 = NEW_node;
	return (NEW_node);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @head: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *head)
{
	size_t i = 0;

	while (head)
	{
		_puts(head->str ? head->str : "(nil)");
		_puts("\n");
		head = head->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @h: address of pointer to first node
 * @in1: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **h, unsigned int in)
{
	list_t *node1, *prev_node;
	unsigned int i = 0;

	if (!h || !*h)
		return (0);

	if (!in1)
	{
		node1 = *h;
		*h = (*h)->next;
		free(node1->str);
		free(node1);
		return (1);
	}
	node1 = *h;
	while (node1)
	{
		if (i == in1)
		{
			prev_node->next = node1->next;
			free(node1->str);
			free(node1);
			return (1);
		}
		i++;
		prev_node = node1;
		node1 = node1->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @h_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **h_ptr)
{
	list_t *node, *next_node, *h;

	if (!h_ptr || !*h_ptr)
		return;
	h = *h_ptr;
	node = h;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*h_ptr = NULL;
}
