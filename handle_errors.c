#include "monty.h"

/**
 * print_error - Prints appropriate error messages
 * determined by the error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or gives more than
 * one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => The program is unable to malloc more memory.
 * (5) => The parameter passed to the instruction "push" is not an int.
**/
void print_error(int error_code, ...)
{
	va_list args;
	char *op_code;
	int num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(args, char *));
			break;
		case 3:
			num = va_arg(args, int);
			op_code = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num, op_code);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * print_other_errors - Prints errors depending on the error code.
 * @error_code: The error codes are the following:
 * (6) => When the stack is empty for pint.
 * (7) => When the stack is empty for pop.
 * (8) => When the stack is too short for operation.
 * (9) => Division by zero.
 */
void print_other_errors(int error_code, ...)
{
	va_list args;
	char *op_code;
	int num;

	va_start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(args, int));
			break;
		case 8:
			num = va_arg(args, unsigned int);
			op_code = va_arg(args, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num, op_code);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * print_more_errors - handles errors.
 * @error_code: The error codes are the following:
 * (10) => The number inside a node is outside ASCII bounds.
 * (11) => The stack is empty.
 */
void print_more_errors(int error_code, ...)
{
	va_list args;
	int num;

	va_start(args, error_code);
	num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
