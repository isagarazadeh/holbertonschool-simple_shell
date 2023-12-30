#include "main.h"

/**
 * main - Runs the shell.
 * @argc: number of arguments
 * @argv: an array of C-style strings
 * @envp: initialism for parameter
 * Return: Exit status 0
 */
int main(__attribute__((unused)) int argc, char **argv, char **envp)
{
int exit_status = 1;
size_t buffer_size;
char *input_line;
char **tokenized_input = NULL;
int is_terminal;
int special_command;

while (exit_status)
{
buffer_size = 100;
input_line = NULL;
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
return (EXIT_SUCCESS);
}
else if (special_command == 1)
{
free(input_line), free(tokenized_input);
continue;
}
exit_status = create_fork(argv[0], tokenized_input, envp, is_terminal);
free(input_line), free(tokenized_input);
}
return (EXIT_SUCCESS);
}

