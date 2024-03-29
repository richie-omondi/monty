#include "monty.h"

/**
 * push - Adds a node to the top of the stack.
 * @new_node: Pointer to the new node to be pushed.
 * @line_number: Integer representing the line number of the opcode.
 */
void push(stack_t **new_node, unsigned int line_number)
{
	stack_t *temp;
	(void) line_number;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);

	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}

/**
 * print_entire_stack - Prints all the values in a stack.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_entire_stack(stack_t **stack,
		__attribute__((unused))unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * print_stack_top - Prints the top node of the stack.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void print_stack_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		print_other_errors(6, line_number);
	printf("%d\n", (*stack)->n);
}

/**
 * pop - Removes the top node from the stack.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		print_other_errors(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer pointing to the top node of the stack.
 * @line_number: Integer representing the line number of the opcode.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		print_other_errors(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
