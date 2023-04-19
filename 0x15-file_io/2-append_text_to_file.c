i#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: filename.
 * @text_content: added content.
 * code by KENNY 
 * Return: if the file exist - 1.
 * if otherwise - -1.
 * or if it fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int nor;
	int nletters;
	int r;

	if (!filename)
		return (-1);

	nor = open(filename, O_WRONLY | O_APPEND);

	if (nor == -1)
		return (-1);

	if (text_content)
	{
		for (nletters = 0; text_content[nletters]; nletters = nletters + 1)
			;

		r = write(nor, text_content, nletters);

		if (r == -1)
			return (-1);
	}

	close(nor);

	return (1);
}i
