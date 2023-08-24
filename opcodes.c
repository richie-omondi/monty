/**
 * push_to_stack - Adds a node to the top of the stack.
 * @new_node: Pointer to the new node to be pushed.
 * @line_number: Integer representing the line number of the opcode.
 */
void push_to_stack(stack_t **new_node, unsigned int line_number)
{
	stack_t *temp;
  	(void) unsigned int line_number;

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
