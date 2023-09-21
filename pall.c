#include "monty.h"

void pall(stack_t **node, unsigned int value)
{
	stack_t *current;

	current = *node;

	(void)value;

	if (current == '\0')
		return;

	while (current != '\0')
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
