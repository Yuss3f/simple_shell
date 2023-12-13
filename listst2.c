#include "shell.h"

/**
 * lst_len - determining the length of linked list
 * @hd: pointer to first node
 *
 * Return: size of list
 */
size_t lst_len(const list_t *hd)
{
	size_t i = 0;

	while (hd)
	{
		hd = hd->nxt;
		i++;
	}
	return (i);
}

/**
 * lst_to_strings - returning an array of strings of the list->str
 * @hd: pointer to first node
 *
 * Return: array of strings
 */
char **lst_to_strings(list_t *hd)
{
	list_t *node = hd;
	size_t i = lst_len(hd), j;
	char **strs;
	char *str;

	if (!hd || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->nxt, i++)
	{
		str = malloc(_strlen(node->st) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->st);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_lst - print all elements of a list_t linked list
 * @hd: pointer to the first node
 *
 * Return: size of list
 */
size_t print_lst(const list_t *hd)
{
	size_t i = 0;

	while (hd)
	{
		_puts(convert_number(hd->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hd->st ? hd->st : "(nil)");
		_puts("\n");
		hd = hd->nxt;
		i++;
	}
	return (i);
}

/**
 * nod_start_with - returns node whose string starts with prefix
 * @n: pointer to list head
 * @prfx: string to match
 * @ch: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *nod_start_with(list_t *n, char *prfx, char ch)
{
	char *p = NULL;

	while (n)
	{
		p = starts_with(n->st, prfx);
		if (p && ((ch == -1) || (*p == ch)))
			return (n);
		n = n->nxt;
	}
	return (NULL);
}

/**
 * get_nod_idx - gets the index of a node
 * @hd: pointer to the list head
 * @n: pointer to node
 *
 * Return: index of node or -1
 */
ssize_t get_nod_idx(list_t *hd, list_t *n)
{
	size_t i = 0;

	while (hd)
	{
		if (hd == n)
			return (i);
		hd = hd->nxt;
		i++;
	}
	return (-1);
}
