#include <stdlib.h>

char *get_int(int num);
unsigned int _abs(int);
int get_numbase_len(unsigned int num, unsigned int base);
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size);

/**
 * get_int - gets a character pointer to new string
 * @num: number to convert to string
 *
 * Return: character pointer, NULL if malloc fails
 */
char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_1 = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_1 < 0)
		length++;
	ret = malloc(length + 1);
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_1 < 0)
		ret[0] = '_';

	return (ret);
}

/**
 * _abs - gets absolute value
 * @i: integer to get absolute value of
 *
 * Return: unsigned integer abs rep of i
 */
unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - gets length of buffer needed for an unsigned int
 * @num: number to get length needed for
 * @base: base of number represantation used by buffer
 *
 * Return: integer containing length of buffer, else NULL
 */
int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1;

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - fills buffer with correct numbers
 * @num: number to convert to string
 * @base: base of number used in conversion
 * @buff: beffer to fill with results
 * @buff_size: size of buffer
 *
 * Return: void always
 */
void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9)
			buff[i] = rem + 87;
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

