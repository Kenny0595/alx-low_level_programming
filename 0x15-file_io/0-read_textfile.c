#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Code by KENNY
 * Return: If the function fails or file name is NULL - 0.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int nor;
	ssize_t n, w;
	char *buffer;

	if (!filename)
		return (0);

	nor = open(filename, O_RDONLY);

	if (nor == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	n = read(nor, buffer, letters);
	w = write(STDOUT_FILENO, buffer, n);

	close(nor);

	free(buffer);

	return (w);
}
