#include "main.h"

/**
 * _strlen - returns the length of a string
 * @str: pointer to string
 * Return: length of the string
 */
int _strlen(char *str)
{
	int length = 0, index = 0;

	while (str[index] != '\0')
	{
		index++;
		length++;
	}
	return (length);
}

/**
 * _strcpy - function that copies the string pointed to by src,
 * including null byte
 * @destination: pointer to the destination string
 * @source: pointer to the source string
 * Return: pointer to destination string
 */
char *_strcpy(char *destination, char *source)
{
	int copy_index = 0;

	while (source[copy_index] != '\0')
	{
		destination[copy_index] = source[copy_index];
		copy_index++;
	}
	destination[copy_index] = '\0';
	return (destination);
}

/**
 * _strcat - function that concatenates two strings
 * @destination: pointer to the destination array
 * @source: pointer to the source array
 * Return: pointer to destination array
 */
char *_strcat(char *destination, char *source)
{
	int dest_length = 0, source_index = 0;

	while (destination[dest_length] != '\0')
		dest_length++;

	while (source[source_index] != '\0')
	{
		destination[dest_length] = source[source_index];
		dest_length++;
		source_index++;
	}

	destination[dest_length] = '\0';
	return (destination);
}

