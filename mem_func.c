#include "shell.h"

/**
 **_memset - fill memory with constant byte
 *@sp: pointer to memory area
 *@by: byte to fill *sp with
 *@nm: amount of bytes to be filled
 *Return: (sp) a pointer to the memory area s
 */
char *_memset(char *sp, char by, unsigned int nm)
{
	unsigned int i;

	for (i = 0; i < nm; i++)
		sp[i] = by;
	return (sp);
}

/**
 * ffree - free a string of strings
 * @ss: string of strings
 */
void ffree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _realloc - reallocating a block of memory
 * @pt: the pointer to previous malloc'ated block
 * @old_sze: the byte size of previous block
 * @new_sze: the byte size of new block
 *
 * Return: pointer to the old block name.
 */
void *_realloc(void *pt, unsigned int old_sze, unsigned int new_sze)
{
	char *p;

	if (!pt)
		return (malloc(new_sze));
	if (!new_sze)
		return (free(pt), NULL);
	if (new_sze == old_sze)
		return (pt);

	p = malloc(new_sze);
	if (!p)
		return (NULL);

	old_sze = old_sze < new_sze ? old_sze : new_sze;
	while (old_sze--)
		p[old_sze] = ((char *)pt)[old_sze];
	free(pt);
	return (p);
}
