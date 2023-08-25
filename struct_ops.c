#include "monty.h"

/**
 * free_node - Frees a node in the stack.
 */
void free_node(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

/**
 * create_node - Creates a node.
 * @data: Data to go inside the node.
 * Return: Pointer to the node, otherwise NULL.
 */
stack_t *create_node(int data)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		print_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = data;
	return (node);
}

/**
 * call_function - Calls the required function.
 * @func: Pointer to the function that is to be called.
 * @op_code: string representing the opcode.
 * @num: a string representing a numeric value.
 * @line_number: line number for the instruction.
 * @data_structure: If 0, nodes will be added as a stack.
 * If 1, nodes will be added as a queue.
 */
void call_function(opcode_function func, char *op_code, char *num,
		int line_number, int data_structure)
{
	stack_t *node;
	int multiplier = 1;
	int i;

	if (strcmp(op_code, "push") == 0)
	{
		if (num != NULL && num[0] == '-')
		{
			num = num + 1;
			multiplier = -1;
		}
		if (num == NULL)
			print_error(5, line_number);
		for (i = 0; num[i] != '\0'; i++)
		{
			if (isdigit(num[i]) == 0)
				print_error(5, line_number);
		}
		node = create_node(atoi(num) * multiplier);
		if (data_structure == 0)
			func(&node, line_number);
		if (data_structure == 1)
			add_to_queue(&node, line_number);
	}
	else
		func(&head, line_number);
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_number: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, unsigned int line_number)
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
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}

/**
 * find_function - find the appropriate function for the opcode
 * @opcode: opcode
 * @opcode_argument: argument of opcode
 * @data_structure: If 0, nodes will be added as a stack.
 * If 1, nodes will be added as a queue.
 * @line_number: line number
 *
 * Return: void
 */
void find_function(char *opcode, char *opcode_argument,
		int line_number, int data_structure)
{
	int i;
	int multiplier;

	instruction_t function_list[] = {
		{"push", push},
		{"pall", print_entire_stack},
		{"pint", print_stack_top},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (multiplier = 1, i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			call_function(function_list[i].f, opcode, opcode_argument,
					line_number, data_structure);
			multiplier = 0;
		}
	}
	if (multiplier == 1)
		print_error(3, line_number, opcode);
}

