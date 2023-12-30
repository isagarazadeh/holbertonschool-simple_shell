#include "main.h"

/**
 * special_cases - Handles special cases when the program
 * token is "exit" or "env".
 *
 * @tokens: Tokens from stdin in this program
 * @shell_name: Name of the executable of this program
 * @environment: Shell environment of this program
 *
 * Return: 0 if the shell should exit, 1 if the shell should continue,
 * 2 if neither
 */
int special_cases(char **tokens, char *shell_name, char **environment)
{
	if (tokens[0])
	{
		if (_strcmp(tokens[0], "exit") == 0)
		{
			if (!tokens[1])
				return (0);
			write(1, shell_name, _strlen(shell_name));
			write(1, ": sh: 1: exit: Illegal number: ", 31);
			write(1, tokens[1], _strlen(tokens[1]));
			write(1, "\n", 1);

			return (1);
		}
		if (_strcmp(tokens[0], "env") == 0)
		{
			int index = 0;
			int string_length = 0;

			while (environment[index])
			{
				string_length = _strlen(environment[index]);
				write(1, environment[index], string_length);
				write(1, "\n", 1);
				index++;
			}
			return (1);
		}
	}
	return (2);
}
