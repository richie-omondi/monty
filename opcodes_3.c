#include "monty.h"

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
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
	int character;

	if (stack == NULL || *stack == NULL)
		print_more_errors(11, line_number);

	character = (*stack)->n;
	if (character < 0 || character > 127)
		print_more_errors(10, line_number);
	printf("%c\n", character);
}

/**
 * print_string - Prints the string at the top of the stack.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_string(stack_t **stack, unsigned int line_number)
{
	int character;
	stack_t *temp;

	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		character = temp->n;
		if (character <= 0 || character > 127)
			break;
		printf("%c", character);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - Rotates the first node of the stack to the bottom
 * and the second top element of the stack becomes the first one.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

/**
 * rotr - Rotates the last node of the stack to the top.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
