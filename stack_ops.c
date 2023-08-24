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
		handle_error(4);
	node->next = NULL;
	node->prev = NULL;
	node->data = data;
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
void call_function(opcode_function func, char *op_code, char *num, int line_number, int data_structure)
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
			if (isdigit(val[i]) == 0)
				print_error(5, line_number);
		}
		node = create_node(atoi(num) * flag);
		if (data_structure == 0)
			func(&node, line_number);
		if (data_structure == 1)
			add_to_queue(&node, line_number);
	}
	else
		func(&head, line_no);
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @line_no: line number of the opcode.
 */
void add_to_queue(stack_t **new_node, unsigned int line_no)
{
	stack_t *temp;
	(void) unsigned int line_no;

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
void find_function(char *opcode, char *opcode_argument, int line_number, int data_structure)
{
	int i;
	int multiplier;

	instruction_t function_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (multiplier = 1, i = 0; function_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, function_list[i].opcode) == 0)
		{
			call_function(function_list[i].f, opcode, opcode_argument, line_number, data_structure);
			multiplier = 0;
		}
	}
	if (multiplier == 1)
		print_error(3, line_number, opcode);
}

