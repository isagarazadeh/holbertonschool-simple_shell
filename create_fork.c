#include "main.h"

/**
 * create_fork - Creates a new process to execute a command
 *
 * @_shell: The name of the shell program
 * @cmd_tokens: An array of strings representing the command and its arguments
 * @env: The array of strings representing the environment variables
 * @is_terminal: Flag indicating whether the shell is running in a terminal
 * Return: The exit status of the command
 */
int create_fork(char *_shell, char **cmd_tokens, char **env, int is_terminal)
{
pid_t child_pid;
int status;
char *full_executable_path, *path_variable;

child_pid = fork();
if (child_pid == -1)
{
perror("Fork Error:");
return (1);
}
else if (child_pid == 0)
{
if (!cmd_tokens || !cmd_tokens[0])
return (1);
execve(cmd_tokens[0], cmd_tokens, env), path_variable = get_path(env);
full_executable_path = split_path(cmd_tokens[0], path_variable);
if (full_executable_path != NULL && path_variable != NULL)
{
char *original_executable_name = cmd_tokens[0];
cmd_tokens[0] = full_executable_path, execve(cmd_tokens[0], cmd_tokens, env);
cmd_tokens[0] = original_executable_name, free(full_executable_path);
}
if (cmd_tokens != NULL && *cmd_tokens != NULL)
{
write(2, _shell, _strlen(_shell));
if (is_terminal)
{
write(1, ": No such file or directory\n", 28);
return (127);
}
else
{
write(2, ": 1: ", 5);
write(2, cmd_tokens[0], _strlen(cmd_tokens[0])), write(2, ": not found\n", 12);
return (127);
}
}
return (1);
}
wait(&status);
if (WIFEXITED(status))
	status = WEXITSTATUS(status);
return (status);
}
