#include "monty.h"

void swap(stack_t **stack, unsigned int last_line)
{
	stack_t *first, *second;

	if (stack[0] == '\0' || stack[0]->next == '\0')
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", last_line);
		exit(EXIT_FAILURE);
	}
	first = stack[0];
	second = stack[0]->next;
	if (first->next->next != '\0')
	{
		first->next = second->next;
		second->next->prev = first;
	}
	else
		first->next = '\0';
	first->prev = second;

	second->next = first;
	second->prev = '\0';
	*stack = second;
}


