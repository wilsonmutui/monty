#include <stdio.h>
#include "monty.h"

arguments_t *arg = NULL;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/**
 * main - program entry
 * @argc: argument count
 * @argv: array of arguments availed
 *
 * Return: EXIT_SUCCESS on success EXIT_FAILURE on fail
 */
int main(int argc, char *argv[])
{
	FILE *mfile;
	char *line;
	size_t i = 0;
	ssize_t x = 1;
	stack_t *list = NULL;
	unsigned int y = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	arg = malloc(sizeof(arguments_t));
	if (arg == NULL)
	{
		malloc_fail();
	}
	arg->l = 0;
	mfile = fopen(argv[1], "r");
	arg->montyfile = mfile;
	if (arg->montyfile == NULL || mfile == NULL)
	{
		fileopen(argv[1]);
	}

	while (x > 0)
	{
		line = NULL;
		x = getline(&line, &i, mfile);
		arg->line = line;
		y++;
		if (x > 0)
		{
			getfunc(line, &list, y, mfile);
		}
		free(line);
	}
	frees(list);
	fclose(mfile);
	free(arg);
	return (0);
}

/**
 * frees - frees linked list stack
 * @h: pointer to head of linked list
 */
void frees(stack_t *h)
{
	stack_t *a = h;

	if (h == NULL)
	{
		return;
	}
	while (h != NULL)
	{
		a = h;
		h = h->next;
		free(a);
	}
}

/**
 * all_free - frees all allocated memory
 *
 */
void all_free(void)
{
	fclose(arg->montyfile);
	free(arg->line);
}