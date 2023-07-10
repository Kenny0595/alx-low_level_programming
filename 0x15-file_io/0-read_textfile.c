#include "main.h"

/**
 * read_textfile - reads a text file and prints the letters
 * @filename: filename.
 * @letters: nums of letters printed.
 * This code is constructed by KENNY
 * wishing myself a goodluck 
 * Return: nums of letters printed. return 0 if it fails.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int kar;
	ssize_t nrd, nwr;
	char *buf;

	if (!filename)
		return (0);

	kar = open(filename, O_RDONLY);

	if (kar == -1)
		return (0);

	buf = malloc(sizeof(char) * (letters));
	if (!buf)
		return (0);

	nrd = read(kar, buf, letters);
	nwr = write(STDOUT_FILENO, buf, nrd);

	close(kar);

	free(buf);

	return (nwr);
}
