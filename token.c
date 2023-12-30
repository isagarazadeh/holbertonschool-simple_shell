#include "main.h"

/**
 * str_tokens - Returns an array of pointers
 * to individual tokens in the 'input_string'
 * using "strtok(input_string, " \n")".
 *
 * The returned array is null pointer-terminated.
 * It's also malloc'ed, and needs to be freed.
 * If it fails to malloc or if 'input_string' is NULL,
 * str_tokens returns NULL.
 *
 * @input_string: The input string to tokenize
 * Return: NULL-terminated array of pointers
 * to tokens in the 'input_string' string
 * if the malloc call was successful, NULL otherwise
 */
char **str_tokens(char *input_string)
{
	char **tokens_array;
	char *token;
	int input_length;
	int tokens_index = 0;

	if (!input_string)
		return (NULL);

	input_length = _strlen(input_string);

	tokens_array = malloc(sizeof(char *) * (input_length + 1));
	if (!tokens_array)
		return (NULL);

	token = strtok(input_string, " \n");
	while (token)
	{
		tokens_array[tokens_index] = token;
		tokens_index++;
		token = strtok(NULL, " \n");
	}
	tokens_array[tokens_index] = NULL;

	return (tokens_array);
}

