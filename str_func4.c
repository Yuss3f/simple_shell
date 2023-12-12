#include "shell.h"

/**
 * **strtow - spliting a string into words, Repeated delimiters are ignored
 * @st: input string
 * @dl:delimeter string
 * Return: pointer to an array of strings, or NULL on failure
 */

char **strtow(char *st, char *dl)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	if (!dl)
		dl = " ";
	for (i = 0; st[i] != '\0'; i++)
		if (!is_delim(st[i], dl) && (is_delim(st[i + 1], dl) || !st[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (is_delim(st[i], dl))
			i++;
		k = 0;
		while (!is_delim(st[i + k], dl) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = st[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * **strtow2 - spliting a string into words
 * @st: input string
 * @dl: delimeter
 * Return: pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *st, char dl)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (st == NULL || st[0] == 0)
		return (NULL);
	for (i = 0; st[i] != '\0'; i++)
		if ((st[i] != dl && st[i + 1] == dl) ||
		    (st[i] != dl && !st[i + 1]) || st[i + 1] == dl)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (st[i] == dl && st[i] != dl)
			i++;
		k = 0;
		while (st[i + k] != dl && st[i + k] && st[i + k] != dl)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
