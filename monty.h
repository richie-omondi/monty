#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/** Stack **/

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head;

/* Struct */

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef void (*opcode_function)(stack_t **, unsigned int);

/* Data structure operations*/
stack_t *create_node(int data);
void free_node(void);
void call_function(opcode_function func, char *op_code, char *num, int line_number, int data_structure);
void find_function(char *opcode, char *opcode_argument, int line_number, int data_structure);
int tokenize(char *input, int line_number, int data_structure);
void open_file(char *pathname);
void read_input_in_file(FILE *fd);
void add_to_queue(stack_t **new_node, unsigned int line_number);

/* Opcode operations */
void push(stack_t **new_node, unsigned int line_number);
void print_entire_stack(stack_t **stack, __attribute__((unused))unsigned int line_number);
void print_stack_top(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void div_nodes(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void print_char(stack_t **stack, unsigned int line_number);
void print_string(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);

/** Print errors **/
void print_error(int error_code, ...);
void print_other_errors(int error_code, ...);
void print_more_errors(int error_code, ...);

#endif
