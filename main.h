#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/**
 * str_tokens - Tokenizes a string into an array of strings.
 *
 * @str: The input string to be tokenized.
 * Return: An array of strings representing the tokens.
 */
char **str_tokens(char *str);

/**
 * create_fork - Creates a new process to execute a command.
 *
 * @shell_name: The name of the shell program.
 * @tokens: An array of strings representing the command
 * and its arguments.
 * @env: The array of strings representing the environment variables.
 * @is_terminal: Flag indicating whether
 * the shell is running in a terminal.
 * Return: The exit status of the command.
 */
int create_fork(char *shell_name, char **tokens, char **env, int is_terminal);

/**
 * special_cases - Handles special cases, such as built-in commands.
 *
 * @tokens: An array of strings representing
 * the command and its arguments.
 * @shell_name: The name of the shell program.
 * @env: The array of strings representing the environment variables.
 * Return: The exit status of the command.
 */
int special_cases(char **tokens, char *shell_name, char **env);

/**
 * get_path - Retrieves the PATH environment variable.
 *
 * @env: The array of strings representing the environment variables.
 * Return: A string containing the PATH variable.
 */
char *get_path(char **env);

/**
 * split_path - Splits a file token using the provided path.
 *
 * @file_token: The token representing the file name.
 * @path: The PATH variable.
 * Return: The full path to the file.
 */
char *split_path(char *file_token, char *path);

/**
 * _strlen - Calculates the length of a string.
 *
 * @s: The input string.
 * Return: The length of the string.
 */
int _strlen(char *s);

/**
 * _strcmp - Compares two strings.
 *
 * @a: The first string.
 * @b: The second string.
 * Return: An integer less than, equal to, or greater than zero
 * if a is found to be less than, equal to,
 * or greater than b, respectively.
 */
int _strcmp(char *a, char *b);

/**
 * _strncmp -  Compares two strings up to a specified number of characters.
 *
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of characters to compare.
 * Return: An integer less than, equal to, or greater than zero
 * if s1 is found to be less than, equal to,
 * or greater than s2, respectively.
 */
int _strncmp(const char *s1, const char *s2, size_t n);

/**
 * _strcpy - Copies a string.
 *
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src);

/**
 * _strcat - Concatenates two strings.
 *
 * @dest: The destination string.
 * @src: The source string.
 * Return: A pointer to the destination string.
 */
char *_strcat(char *dest, char *src);

#endif /* MAIN_H */
