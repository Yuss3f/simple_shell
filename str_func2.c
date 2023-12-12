#include "shell.h"

/**
 * _strcpy - copy a string
 * @dst: destination
 * @src: source
 *
 * Return: pointer to dst
 */
char *_strcpy(char *dst, char *src)
{
	int i = 0;

	if (dst == src || src == 0)
		return (dst);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

/**
 * _strdup - duplicating a string
 * @st: string to duplicate
 *
 * Return: pointer to the duplicated st
 */
char *_strdup(const char *st)
{
	int length = 0;
	char *ret;

	if (st == NULL)
		return (NULL);
	while (*st++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--st;
	return (ret);
}

/**
 *_puts - print an input st
 *@st: string to be printed
 *
 * Return: Nothing
 */
void _puts(char *st)
{
	int i = 0;

	if (!st)
		return;
	while (st[i] != '\0')
	{
		_putchar(st[i]);
		i++;
	}
}

/**
 * _putchar - write character c to stdout
 * @c: character to print
 *
 * Return: On success 1.
 * On error, -1 is return, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
