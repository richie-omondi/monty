#include "monty.h"

/**
 * push_to_stack - Adds a node to the top of the stack.
 * @new_node: Pointer to the new node to be pushed.
 * @line_number: Integer representing the line number of the opcode.
 */
void push_to_stack(stack_t **new_node, unsigned int line_number)
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
 * print_stack - Prints all the values in a stack.
 * @stack: Pointer to a pointer pointing to the top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, __attribute__((unused))unsigned int line_number)
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

