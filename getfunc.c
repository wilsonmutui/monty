#include "monty.h"

/**
 * getfunc - check line and execute right function
 * @line: line contents
 * @stack: pointer to pointer of the stack
 * @l: the line number
 * @file: pointer to the monty file
 *
 * Return: 0 - success
 */
int getfunc(char *line, stack_t **stack, unsigned int l, FILE *file)
{
	instruction_t ops[] = {
		{"pall", m_pall},
		{"push", m_push},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{NULL, NULL}
	};

	unsigned int a = 0;
	char *inst = strtok(line, " \n\t");

	if (inst && inst[0] == '#')
		return (0);

	arg->val = strtok(NULL, " \n\t");
	while (ops[a].opcode && inst)
	{
		if (strcmp(inst, ops[a].opcode) == 0)
		{
			ops[a].f(stack, l);
			return (0);
		}
		a++;
	}
	if (inst && ops[a].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", l, inst);
		fclose(file);
		free(line);
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}