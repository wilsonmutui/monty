#include "monty.h"
#include <ctype.h>


void stack_add(stack_t **h, int x);
/**
 * m_push - pushes an element to the stack
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_push(stack_t **stack, unsigned int line_number)
{
	int x = 0, y = 0, z = 1;

	if (arg->val)
	{
		if (arg->val[0] == '-')
			y++;
		while (arg->val[y] != '\0')
		{
			if (!isdigit(arg->val[y]))
			{
				z = 0;
				break;
			}
			y++;
		}
		if (!z)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			all_free();
			frees(*stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
		x = atoi(arg->val);
		stack_add(stack, x);
}

/**
 * stack_add - adds node to the top
 * @h: head of stack
 * @x: integer
 *
 */
void stack_add(stack_t **h, int x)
{
	stack_t *new, *tmp;

	tmp = *h;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new;
	new->n = x;
	new->next = *h;
	new->prev = NULL;
	*h = new;
}

/**
 * m_pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *a = *stack;
	(void) line_number;

	while (a)
	{
		printf("%d\n", a->n);
		a = a->next;
	}
}

/**
 * m_pint - prints the value at the top of the stack,
 * followed by a new line
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * m_pop - removes the top element of the stack
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = temp->next;
	free(temp);
}