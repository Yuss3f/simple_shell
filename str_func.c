#include "shell.h"

/**
 * _strlen - returns length of  string
 * @st: string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *st)
{
	int i = 0;

	if (!st)
		return (0);

	while (*st++)
		i++;
	return (i);
}

/**
 * _strcmp - executes lexicogarphic comparison of two strings.
 * @st1:  first string
 * @st2:  second string
 *
 * Return: negative if st1 < st2, positive if st1 > st2, zero if st1 == st2
 */
int _strcmp(char *st1, char *st2)
{
	while (*st1 && *st2)
	{
		if (*st1 != *st2)
			return (*st1 - *st2);
		st1++;
		st2++;
	}
	if (*st1 == *st2)
		return (0);
	else
		return (*st1 < *st2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to look for
 * @needle: substring to fnd
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	for (; *needle; needle++, haystack++)
	{
		if (*needle != *haystack)
		{
			return (NULL);
		}
	}
	return ((char *)haystack);
}

/**
 * _strcat - concatenate two strings
 * @dst: destination buffer
 * @src: source buffer
 *
 * Return: pointer of destination buffer
 */
char *_strcat(char *dst, char *src)
{
	char *ret = dst;

	while (*dst)
		dst++;
	while (*src)
		*dst++ = *src++;
	*dst = *src;
	return (ret);
}
