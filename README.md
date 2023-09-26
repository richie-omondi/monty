Monty Program
=====================================


Introduction
------------

The Monty program is an interpreter written in C for a stack-based programming language.
It reads Monty bytecode files containing instructions and performs stack operations accordingly. This documentation provides an overview of the program's structure, main components, and functions.

## Table of Contents
1. [Program_Overview](#program_overview)
2. [Data_Structures](#data_structures)
3. [Main_Function](#main_function)
4. [Read_file](#read_file)
5. [Tokenization](#tokenization)
6. [Operations](#operations)
7. [Memory_Management](#memory_management)
8. [Conclusion](#conclusion)

## Program Overview

The Monty program reads and interprets Monty bytecode files line by line.
It executes various stack manipulation and arithmetic operations based on the instruction in the bytecode. The program utilizes a doubly linked list to implement the stack, where nodes contain integers.
- Usage: `monty file`
    - where `file` is the path to the file containing Monty byte code

## Data Structures
### `stack_t` Structure
- Represents a node in the stack.
- Contains:
    - `int n`: Integer value stored in the node.
    - `struct stack_s *prev`: Pointer to the previous node in the stack.
    - `struct stack_s *next`: pointer to the next node in the stack.
```
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

```
### `instruction_t` Structure
- Represents an instruction to be executed.
- Contains:
    - `char *opcode`: Name of the instruction.
    - `void (*f)(stact_t **stack, unsigned int line_number)`: pointer to the function that implements the instruction.
```
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

```
## Main Function
`int main(int ac, char **av)`
- Entry point of the program.
- Parses command line arguments to get the input bytecode file path.
- Calls the `open_file` function to open the file specified by *pathname* then reads the bytecode file for further processing.

## Read the file
`read_input_in_file(FILE *fd)`
- Reads the content of a file specified by the `pathname`.
- Reads the file line by line by calling the `getline` function in a loop until the end of the file is reached (`getline` returns `-1`) 
- processes each line by tokenizing using the `tokenize` function.

## Tokenization
### `tokenize` Function
`int tokenize(char *input, int line_number, int data_structure)`
- Splits a string into an array of tokens based on delimiter characters.
- Returns a number (`0` or `1`) used to determine whether to use a stack or a queue.
- Utilizes the `strtok` function to split the string.

## Operations
### `find_function()` Function
- Executes the appropriate operation based on the given opcode.
- Compares the opcode with a predefined list of instructions and their associated functions.
- If a matching opcode is found, the associated function is called with the stack and line number.

#### Supported Instructions
- `push`: Pushes an integer onto the stack.
- `pall`: prints all elements in the stack.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element from the stack.
- `swap`: Swaps the two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: No operation (does nothing).
- `sub`: Subtracts the top element from the second element in the stack.
- `mul`: Multiplies the top two elements of the stack.
- `mod`: Computes the modulus of the second element by the top element in the stack.
- `pchar`: Prints the character at the top of the stack.
- `pstr`: Prints the string at the top of the stack.
- `rotl`:  Rotates the stack to the top; the top element of the stack becomes the last one, and the second top element of the stack becomes the first one.
- `rotr`:  Rotates the stack to the bottom; the last element of the stack becomes the top element of the stack

## Memory Management
- The program utilizes dynamic memory allocation for creating nodes.
- Memory is properly freed to prevent memory leaks using functions like `free` and `free_node`.

## Conclusion
The Monty program is a simple interpreter that reads and processes Monty bytecode files. It utilizes a stack data structure and supports various stack manipulation and arithmetic operations. This documentation provides an overview of the program's components and functionality to help understand its implementation.
