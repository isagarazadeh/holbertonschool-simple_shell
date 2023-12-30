#include "main.h"
/**
 * create_fork - create_fork.
 * @_shell: shell_name.
 * @cmd_tokens: command_tokens.
 * @env: environment.
 * @is_terminal: terminal
 * Return: anythin.
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
return (0);
}
else if (child_pid == 0)
{
if (!cmd_tokens || !cmd_tokens[0])
return (0);
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
write(1, _shell, _strlen(_shell));
if (is_terminal)
write(1, ": No such file or directory\n", 28);
else
{
write(1, ": 1: ", 5);
write(1, cmd_tokens[0], _strlen(cmd_tokens[0])), write(1, ": not found\n", 12);
}
}
return (0);
}
wait(&status);
if (WIFEXITED(status))
	status = WEXITSTATUS(status);
return (1);
}
