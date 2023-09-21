#include "monty.h"

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	current = *stack;

	(void)line_number;

	if (current == '\0')
		return;

	while (current != '\0')
	{
		printf("%i\n", current->n);
		current = current->next;
	}
}
