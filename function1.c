#include "monty.h"

/**
 * m_swap - swaps the top two elements of the stack
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}

	if (temp && temp->next)
	{
		temp1 = temp->next;
		if (temp1->next)
		{
			temp1->next->prev = temp;
		}
		temp->next = temp1->next;
		temp1->prev = NULL;
		temp1->next = temp;
		temp->prev = temp1;
		*stack = temp1;
	}
}

/**
 * m_add - adds the top two elements of the stack
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1 = temp->next;
	temp1->n += temp->n;
	temp1->prev = NULL;
	*stack = temp1;
	free(temp);
}

/**
 * m_nop - doesn't do anything
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}