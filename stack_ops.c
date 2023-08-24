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
 * call_fn - Calls the required function.
 * @func: Pointer to the function that is to be called.
 * @op_code: string representing the opcode.
 * @num: a string representing a numeric value.
 * @line_no: line number for the instruction.
 * @data_struct. If 0, nodes will be added as a stack.
 * if 1, nodes will be added as a queue.
 */
void call_fn(opcode_func func, char *op_code, char *num, int line_no, int data_struct)
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
			print_error(5, line_no);
		for (i = 0; num[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				print_error(5, line_no);
		}
		node = create_node(atoi(num) * flag);
		if (data_struct == 0)
			func(&node, line_no);
		if (data_struct == 1)
			add_to_queue(&node, line_no);
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
