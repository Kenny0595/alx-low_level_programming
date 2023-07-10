#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 * This code is constructed by KENNY
 * Return: in exitience of the file should return 1 but if otherwise -1
 * i am wishing myself a goodluck
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int kar;
	int nletters;
	int rwr;

	if (!filename)
		return (-1);

	kar = open(filename, O_WRONLY | O_APPEND);

	if (kar == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters = nletters + 1)
			;

		rwr = write(kar, text_content, nletters);

		if (rwr == -1)
			return (-1);
	}

	close(kar);

	return (1);
}
