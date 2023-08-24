#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: Double pointer pointing to top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void add(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_other_errors(8, line_number, "add");

	(*stack) = (*stack)->next;
	sum = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - Does nothing.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
