#include "monty.h"
/**
 * malloc_fail - malloc error
 *
 */
void malloc_fail(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * fileopen - error opening the file
 * @f: pointer to the monty file
 *
 */
void fileopen(char *f)
{
	fprintf(stderr, "Error: Can't open file %s\n", f);
	exit(EXIT_FAILURE);
}
