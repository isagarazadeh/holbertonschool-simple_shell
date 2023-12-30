# Holberton Simple Shell

The Holberton Simple Shell (hsh) project is an integral component of the Holberton School's curriculum. In essence, the hsh serves as a command language interpreter designed to execute commands from a command line string, standard input, or a specified file. Moreover, it adeptly manages the PATH, making it comparable to the Linux Shell.

## Project Requirements

The successful completion of the project entails addressing the following seven tasks:

* Task 0 - Develop a README, Write a man page for your shell, and an AUTHOR file.
* Task 1 - Craft code that adheres to the Betty coding style guidelines.
* Task 2 - Create a UNIX command line interpreter.
* Task 3 - Accommodate command lines with arguments.
* Task 4 - Manage the PATH, ensuring that fork is not invoked if the command does not exist.
* Task 5 - Implement the exit built-in, facilitating the termination of the shell.
* Task 6 - Implement the env built-in, which prints the current environment.

## Project Documentation

### Files Description

* README.md - This file contains comprehensive information, instructions, and details for users about the project.
* AUTHORS - This file includes the names and email addresses of the project's authors.
* man_1_simple shell - A manual page has been created to assist users in understanding how to utilize our project.
* main.h - This file encompasses all function declarations and macro definitions.
* main.c - The primary function resides in this file, serving as the starting point for our program.
* token.c - This file houses the function responsible for creating and returning an array of pointers.
* special_cases.c - Handling of built-ins is managed in this file.
* create_fork.c - This file facilitates the creation of another process, executing commands, and printing error messages.
* get_path.c - PATH handling is effectively managed in this file.
* strings.c - All string functions created and utilized for the project (excluding comparison) are present in this file.
* str_cmp.c - Comparison string functions, created and used for the project, are located in this file.
