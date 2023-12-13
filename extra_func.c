#include "shell.h"

/**
 * interact - returning true if shell is interactive mode
 * @nfo: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interact(info_t *nfo)
{
	return (isatty(STDIN_FILENO) && nfo->readfd <= 2);
}

/**
 * is_dlm - checks if character is a delimeter
 * @ch: the char to check
 * @dlm: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_dlm(char ch, char *dlm)
{
	while (*dlm)
		if (*dlm++ == ch)
			return (1);
	return (0);
}

/**
 *_alpha - check for alphabetic character
 *@ch: character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _alpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoii - converting a string to an integer
 *@st: string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoii(char *st)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  st[i] != '\0' && flag != 2; i++)
	{
		if (st[i] == '-')
			sign *= -1;

		if (st[i] >= '0' && st[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (st[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
