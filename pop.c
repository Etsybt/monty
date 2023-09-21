#include "monty.h"

void pop(stack_t **stack, unsigned int last_number)
{
	stack_t *sst;

	if (*stack == '\0')
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", last_line);
		release(NULL, NULL, 'r');
		free_dlistint(*stack);
		free(global.argument);
		exit(EXIT_FAILURE);
	}
	sst = *stack;
	*stack = stack[0]->next;
	free(sst);
}
