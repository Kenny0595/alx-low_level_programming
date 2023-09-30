#include"main.h"

/**
 * get_endianness - checks if a machine is lit or big endianness
 * Return: 0 for big, 1 for lit
 * This code is contructed by KENNY
 * wishing my self goodluck
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
