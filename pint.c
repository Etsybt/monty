#include "monty.h"

void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == '\0')
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", line_number);
		release(NULL, NULL, 'r');
		free_dlistint(*stack);
		free(global.argument);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", stack[0]->n);
}
