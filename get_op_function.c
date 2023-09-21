#include "monty.h"

void get_op_function(stack_t **top, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"add", add},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	int i;

	for (i = 0; ops[i].opcode != NULL; i++)
	{
		if (strcmp(global.argument[0], ops[i].opcode) == 0)
		{
			ops[i].f(top, line_number);
			return;
		}
	}
	if (ops[i].opcode == NULL)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, global.argument[0]);
		free(global.argument);
		free_dlistint(*top);
		release(NULL, NULL, 'r');
		exit(EXIT_FAILURE);
	}
}
															
