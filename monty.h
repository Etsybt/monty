#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
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
/**
  * struct global_data_s - struct for the global var
  * @argument: args
  * @file: file to be executed
  * @line: line input
  * @m: int
  * Description: global var
  */

typedef struct global_data_s
{
	char *argument;
	FILE *file;
	char *line;
	int m;
} global_data_t;

extern global_data_t global;


void free_head(stack_t *node);
int operate(char *line, stack_t **node, unsigned int line_number, FILE *file);

void push(stack_t **node, unsigned int value);
void pall(stack_t **node, unsigned int value);
void pint(stack_t **node, unsigned int value);
void pop(stack_t **node, unsigned int value);
void swap(stack_t **node, unsigned int value);
void add(stack_t **node, unsigned int value);
void nop(stack_t **node, unsigned int value);

void stacking(stack_t **node, int n);
void rev_stacking(stack_t **node, int n);
void last(stack_t **node, unsigned int line_number);
void frees_head(stack_t **node, unsigned int value);

#endif
