#include "main.h"

/**
 * main - Entry point for the shell program.
 * @argc: Number of command-line arguments.
 * @argv: Array of C-style strings containing command-line arguments.
 * @envp: Array of strings representing the program's environment variables.
 *
 * Return: Exit status 0 upon successful execution.
 */

int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
	size_t buffer_size;
	char *input_line, **tokenized_input = NULL;
	int is_terminal, special_command, exit_status = 0;

	while (1)
	{
		buffer_size = 100, input_line = NULL;
		is_terminal = isatty(0);
		if (is_terminal)
			write(1, "$ ", 2);
		if (getline(&input_line, &buffer_size, stdin) == -1)
		{
			free(input_line);
			break;
		}
		tokenized_input = str_tokens(input_line);
		if (!tokenized_input)
		{
			free(input_line);
			break;
		}
		special_command = special_cases(tokenized_input, argv[0], envp);
		if (special_command == 0)
		{
			free(input_line), free(tokenized_input);
			return (exit_status);
		}
		else if (special_command == 1)
		{
			free(input_line), free(tokenized_input);
			continue;
		}
		exit_status = create_fork(argv[0], tokenized_input, envp, is_terminal);
		if (exit_status == -1)
		{
			fprintf(stderr, "Error executing command\n");
		}
		free(input_line), free(tokenized_input);
	}
	return (exit_status);
}
