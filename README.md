# Holberton Simple Shell

The Holberton Simple Shell (hsh) is a project assigned as part of Holberton School's curriculum. Basically, the hsh is a command language interpreter that executes commands from a command line string, the standard input, or a specified file. It handles the PATH.

This project is similar to the Linux Shell.

## Project Requirements

The project requires complete the following 7 task:

	* Task 0 - Write a README, Write a man for your shell & AUTHOR file.

	* Task 1 - Write a beautiful code that passed the Betty checks

	* Task 2 - Write a UNIX command line interpreter.

	* Task 3 - Handle command lines with arguments

	* Task 4 - Handle the PATH, fork must not be called if the command doesnt exist

	* Task 5 - Implement the exit built-in, that exits the shell

	* Task 6 - Implement the env built-in, that prints the current enviorment

## Project Documentation

### Files Description

	* README.md - File that contains information, instructions and details for the user about the project. THIS FILE!

	* AUTHORS - File that contains the name and email of project's authors.

	* man_1_simple shell - Manual page created to help users understand how to uses our project.

	* main.h - File that contains all functions declarations and macro definitions.

	* main.c - File that contains the primary function, serves as the starting point of our program.

	* token.c - File that contains the function that creates and returns an array of pointers.

	* special_cases.c - File that handle the built-ins.

	* create_fork.c - File that create another process, execute command and print error message.

	* get_path.c - File that handle the PATH.

	* strings.c - File that contains all the string functions created and used for the project (except for comparison).

	* str_cmp.c - File that contains all the compare string functions created and used for the project.

