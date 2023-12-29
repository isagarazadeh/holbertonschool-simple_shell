#include "main.h"

/**
 * get_path - Get the PATH string from the environment
 * @env: Environment list with variables
 * Return: Pointer to the string with all directories
 * in the 'PATH' string
 */
char *get_path(char **environment)
{
	int index;
	char *path_variable = NULL;

	if (!environment)
		return (NULL);

	for (index = 0; environment[index]; index++)
	{
		if (_strncmp(environment[index], "PATH=", 5) == 0)
		{
			path_variable = environment[index];
			break;
		}
	}

	if (path_variable == NULL)
		return (NULL);

	path_variable = strtok(path_variable, "=");

	if (path_variable)
		path_variable = strtok(NULL, "=");

	return (path_variable);
}

/**
 * split_path - Get the full path to the file named
 * 'file_name' if it's in PATH, NULL otherwise
 *
 * THE RETURNED STRING MUST BE FREED!!!!
 *
 * @file_name: Name of executable to find in the path
 * @path_directories: String containing all directories in PATH
 *
 * Return: Full path to file 'file_name' if found
 * in PATH, NULL otherwise
 */
char *split_path(char *file_name, char *path_directories)
{
	struct stat file_stat;
	char *directory;

	if (path_directories == NULL)
		return (NULL);

	directory = strtok(path_directories, ":");

	while (directory)
	{
		int dir_length = _strlen(directory);
		int file_length = _strlen(file_name);

		/* 1 char for slash, 1 char for terminating null byte */
		char *full_file_path = malloc(sizeof(char) * (dir_length + 2 + file_length));

		if (!full_file_path)
			return (NULL);

		_strcpy(full_file_path, directory);
		_strcat(full_file_path, "/");
		_strcat(full_file_path, file_name);

		if (stat(full_file_path, &file_stat) == 0)
			return (full_file_path);

		directory = strtok(NULL, ":");
		free(full_file_path);
	}

	return (NULL);
}

