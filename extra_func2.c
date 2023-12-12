#include "shell.h"

/**
 * _eratoii - converting a string to an integer
 * @st: string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _eratoii(char *st)
{
	int i = 0;
	unsigned long int result = 0;

	if (*st == '+')
		st++;
	for (i = 0;  st[i] != '\0'; i++)
	{
		if (st[i] >= '0' && st[i] <= '9')
		{
			result *= 10;
			result += (st[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * prn_error - prints an error message
 * @nfo: parameter & return info struct
 * @erstr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void prn_error(info_t *nfo, char *erstr)
{
	_eputs(nfo->fname);
	_eputs(": ");
	prn_d(nfo->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(nfo->argv[0]);
	_eputs(": ");
	_eputs(erstr);
}

/**
 * prn_d - function printing a decimal (integer) number (base 10)
 * @inp: input
 * @fld: filedescriptor to write to
 *
 * Return: number of characters printed
 */
int prn_d(int inp, int fld)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fld == STDERR_FILENO)
		__putchar = _eputchar;
	if (inp < 0)
	{
		_abs_ = -inp;
		__putchar('-');
		count++;
	}
	else
		_abs_ = inp;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * cnv_num - converter function, a clone of itoa
 * @nm: number
 * @bse: base
 * @flg: argument flags
 *
 * Return: string
 */
char *cnv_num(long int nm, int bse, int flg)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *pt;
	unsigned long n = nm;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pt = &buffer[49];
	*pt = '\0';

	do	{
		*--pt = array[n % bse];
		n /= bse;
	} while (n != 0);

	if (sign)
		*--pt = sign;
	return (pt);
}

/**
 * rm_comment - a function replacing first instance of '#' with '\0'
 * @bf: address of string to modify
 *
 * Return: Always 0;
 */
void rm_comment(char *bf)
{
	int i;

	for (i = 0; bf[i] != '\0'; i++)
		if (bf[i] == '#' && (!i || bf[i - 1] == ' '))
		{
			bf[i] = '\0';
			break;
		}
}
