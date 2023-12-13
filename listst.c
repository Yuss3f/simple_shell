#include "shell.h"

/**
 * add_nod - adding a node to start of the list
 * @hd: address of pointer to head node
 * @st: str field of node
 * @nm: node index used by history
 *
 * Return: size of list
 */
list_t *add_nod(list_t **hd, const char *st, int nm)
{
	list_t *new_head;

	if (!hd)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = nm;
	if (st)
	{
		new_head->st = _strdup(st);
		if (!new_head->st)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->nxt = *hd;
	*hd = new_head;
	return (new_head);
}

/**
 * add_nod_end - add a node to the end of the list
 * @hd: address of pointer to head node
 * @st: str field of node
 * @nm: node index used by history
 *
 * Return: size of list
 */
list_t *add_nod_end(list_t **hd, const char *st, int nm)
{
	list_t *new_node, *node;

	if (!hd)
		return (NULL);

	node = *hd;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = nm;
	if (st)
	{
		new_node->st = _strdup(st);
		if (!new_node->st)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->nxt)
			node = node->nxt;
		node->nxt = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_lst_st - print only the str element of a list_t linked list
 * @hp: pointer to the first node
 *
 * Return: size of list
 */
size_t print_lst_st(const list_t *hp)
{
	size_t i = 0;

	while (hp)
	{
		_puts(hp->st ? hp->st : "(nil)");
		_puts("\n");
		hp = hp->nxt;
		i++;
	}
	return (i);
}

/**
 * del_nod_at_index - deletes node at given index
 * @hd: address of the pointer to first node
 * @idx: index of the node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int del_nod_at_index(list_t **hd, unsigned int idx)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!hd || !*hd)
		return (0);

	if (!idx)
	{
		node = *hd;
		*hd = (*hd)->nxt;
		free(node->st);
		free(node);
		return (1);
	}
	node = *hd;
	while (node)
	{
		if (i == idx)
		{
			prev_node->nxt = node->nxt;
			free(node->st);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->nxt;
	}
	return (0);
}

/**
 * free_lst - frees all nodes of a list
 * @hd_pt: address of the pointer to head node
 *
 * Return: void
 */
void free_lst(list_t **hd_pt)
{
	list_t *node, *next_node, *hd;

	if (!hd_pt || !*hd_pt)
		return;
	head = *hd_pt;
	node = head;
	while (node)
	{
		next_node = node->nxt;
		free(node->st);
		free(node);
		node = next_node;
	}
	*hd_pt = NULL;
}
