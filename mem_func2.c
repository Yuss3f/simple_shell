#include "shell.h"

/**
 * befree - frees a pointer and NULLs the address
 * @pt: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int befree(void **pt)
{
	if (pt && *pt)
	{
		free(*pt);
		*pt = NULL;
		return (1);
	}
	else
	{
	return (0);
}
