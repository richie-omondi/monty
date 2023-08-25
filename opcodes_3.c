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

/**
 * print_char - Prints the character at the top of the stack
 * followed by a new line.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int char;

	if (stack == NULL || *stack == NULL)
		print_more_errors(11, line_number);

	char = (*stack)->n;
	if (char < 0 || char > 127)
		print_more_errors(10, line_number);
	printf("%c\n", char);
}