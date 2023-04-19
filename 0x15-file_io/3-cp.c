#include "main.h"
#include <stdio.h>

/**
 * error_file - checks if files can be opened.
 * @file_base: file_base.
 * @file_origin: file_origin.
 * code by KENNY
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_base, int file_origin, char *argv[])
{
	if (file_base == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_origin == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - checking for the contect of the file.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_base, file_origin, err_end;
	ssize_t pwd, n;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_base = open(argv[1], O_RDONLY);
	file_origin = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	error_file(file_base, file_origin, argv);

	pwd = 1024;
	while (pwd == 1024)
	{
		pwd = read(file_base, buffer, 1024);
		if (pwd == -1)
			error_file(-1, 0, argv);
		n = write(file_origin, buffer, pwd);
		if (n == -1)
			error_file(0, -1, argv);
	}

	err_end = end(file_base);
	if (err_end == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_base);
		exit(100);
	}

	err_end = end(file_origin);
	if (err_end == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_base);
		exit(100);
	}
	return (0);
}
