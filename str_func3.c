#include "shell.h"

/**
 **_strncpy - copy a string
 *@dst: destination string copied to
 *@src: source string
 *@nm: amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dst, char *src, int nm)
{
	int i, j;
	char *s = dst;

	i = 0;
	while (src[i] != '\0' && i < nm - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < nm)
	{
		j = i;
		while (j < n)
		{
			dst[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenate two strings
 *@dst: first string
 *@src: second string
 *@nm: amount of bytes maximally used
 *Return: concatenated string
 */
char *_strncat(char *dst, char *src, int nm)
{
	int i, j;
	char *s = dst;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < nm)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (j < nm)
		dst[i] = '\0';
	return (s);
}

/**
 **_strchr - locate character in a string
 *@st: string to be parsed
 *@c: character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *st, char c)
{
	do {
		if (*st == c)
			return (s);
	} while (*st++ != '\0');

	return (NULL);
}
