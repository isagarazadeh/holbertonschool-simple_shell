#include "shell.h"

/**
 * main - Runs the shell.
 *
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
tokenized_input = tokenize_string(input_line);
if (!tokenized_input)
{
free(input_line);
break;
}
special_command = handle_special_cases(tokenized_input, argv[0], envp);
if (special_command == 0)
{
free(input_line);
free(tokenized_input);
return (EXIT_SUCCESS);
}
else if (special_command == 1)
{
free(input_line);
free(tokenized_input);
continue;
}
exit_status = execute_command(argv[0], tokenized_input, envp, is_terminal);
free(input_line);
free(tokenized_input);
}
return (EXIT_SUCCESS);
}
