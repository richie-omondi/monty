#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	int modulus;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		print_other_errors(8, line_number, "mod");


	if ((*stack)->n == 0)
		print_other_errors(9, line_number);
	(*stack) = (*stack)->next;
	modulus = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = modulus;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
