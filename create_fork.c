#include "main.h"

int create_fork(char *shell_name, char **command_tokens, char **environment, int is_terminal)
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("Fork Error:");
return (0);
}
else if (child_pid == 0)
{
char *full_executable_path;
char *path_variable;

if (!command_tokens || !command_tokens[0])
return (0);

execve(command_tokens[0], command_tokens, environment);

// Executable not found, try to find it in the PATH variable
path_variable = get_path(environment);
full_executable_path = split_path(command_tokens[0], path_variable);

if (full_executable_path != NULL && path_variable != NULL)
{
char *original_executable_name = command_tokens[0];

command_tokens[0] = full_executable_path;
execve(command_tokens[0], command_tokens, environment);

// Restore the original executable name in case execve fails
command_tokens[0] = original_executable_name;
free(full_executable_path);
}

// Handle the case where the executable is not found
if (command_tokens != NULL && *command_tokens != NULL)
{
write(1, shell_name, _strlen(shell_name));

if (is_terminal)
write(1, ": No such file or directory\n", 28);
else
{
write(1, ": 1: ", 5);
write(1, command_tokens[0], _strlen(command_tokens[0]));
write(1, ": not found\n", 12);
}
}

return (0);
}
else
{
wait(&status);
}
return (1);
}

