#include "main.h"

/**
 * _strcmp - Compares two strings.
 * @str1: First string to compare
 * @str2: Second string to compare
 * Return: 0 if the strings are the same, otherwise a
 * positive or negative value
 */
int _strcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return (0);
		}
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strncmp - Compares n bytes of two strings.
 * @str1: Character string
 * @str2: Character string
 * @n: Number of bytes to compare
 * Return: 0 if the strings are the same
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);

	do {
		if (*str1 != *str2++)
			return (*(unsigned char *)str1 - *(unsigned char *)--str2);
		if (*str1++ == 0)
			break;
	} while (--n != 0);

	return (0);
}
