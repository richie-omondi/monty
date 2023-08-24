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
 * add_node - Adds a node.
 * @data: Data to go inside the node.
 * Return: Pointer to the node, otherwise NULL.
 */
stack_t *add_node(int data)
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
void call_fn(op_func func, char *op_code, char *num, int line_no, int data_struct)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}
