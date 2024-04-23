#include "monty.h"

/**
 * m_sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1 = temp->next;
	temp1->n -= temp->n;
	temp1->prev = NULL;
	*stack = temp1;
	free(temp);

}

/**
 * m_div - divides the second top element of the stack
 * by the top element of the stack.
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1 = temp->next;
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1->n /= temp->n;
	temp1->prev = NULL;
	*stack = temp1;
	free(temp);
}


/**
 * m_mul - multiplies the second top element of the stack
 * with the top element of the stack.
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1 = temp->next;
	temp1->n *= temp->n;
	temp1->prev = NULL;
	*stack = temp1;
	free(temp);
}
/**
 * m_mod - computes the rest of the division of the second top element
 * by the top element of the stack
 * @stack: pointer of pointer to actual stack
 * @line_number: file line number
 *
 */
void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack, *temp1;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1 = temp->next;
	if (temp1->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		all_free();
		frees(*stack);
		exit(EXIT_FAILURE);
	}
	temp1->n %= temp->n;
	temp1->prev = NULL;
	*stack = temp1;
	free(temp);
}