#include "main.h"

/**
 * str_tokens - Tokenizes a string into an array of strings.
 *
 * @input_string: The input string to be tokenized.
 * Return: An array of strings representing the tokens.
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

