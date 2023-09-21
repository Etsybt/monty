#include "monty.h"
/**
  * operate - the opcodes
  * @line: line input
  * @node: first node
  * @line_number: number of line
  * @file: file
  * Return: void
  */
int operate(char *line, stack_t **node, unsigned int line_number, FILE *file)
{
	instruction_t opst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(line, " \n\t");

	if (op && op[0] == '#')
		return (0);
	global.argument = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(node, line_number);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(line);
		free_head(*node);
		exit(EXIT_FAILURE);
	}
	return (1);
}
