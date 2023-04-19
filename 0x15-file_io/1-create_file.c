#include "main.h"

/**
 * create_file - creates a file
 * @filename: filename.
 * @text_content: content writed in the file.
 * code by KENNY  
 * Return: if function fails - -1.
 *         or 1 if it success
 */
int create_file(const char *filename, char *text_content)
{
	int nor;
	int nletters;
	int r;

	if (!filename)
		return (-1);

	nor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (nor == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (nletters = 0; text_content[nletters]; nletters = nletters + 1)
		;

	r = write(nor, text_content, nletters);

	if (r == -1)
		return (-1);

	close(nor);

	return (1);
}
