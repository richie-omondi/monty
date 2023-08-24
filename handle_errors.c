#include "monty.h"

/**
 * handle_error - Prints appropriate error messages determined by their error code.
 * @error_code: The error codes are the following:
 * (1) => The user does not give any file or gives more than one file to the program.
 * (2) => The file provided is not a file that can be opened or read.
 * (3) => The file provided contains an invalid instruction.
 * (4) => The program is unable to malloc more memory.
 * (5) => The parameter passed to the instruction "push" is not an int.
**/
void handle_error(int error_code, ...)
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
