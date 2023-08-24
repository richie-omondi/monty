#include "monty.h"

/**
 * tokenize - tokenizes the input
 * @input: line from the file
 * @line_number: line number
 * @data_structure:  If 0, nodes will be added as a stack.
 * If 1, nodes will be added as a queue.
 * Return: 0 If the data structure is a stack.
 * 1 if it's a queue.
 */

int tokenize(char *input, int line_number, int data_structure)
{
	char *opcode, *opcode_argument;
	const char *delimiter = "\n ";

	if (input == NULL)
		print_error(4);

	opcode = strtok(input, delimiter);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delimiter);

	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);

	find_function(opcode, opcode_argument, line_number, data_structure);
	return (data_structure);
}
