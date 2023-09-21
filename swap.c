#include "monty.h"

void swap(stack_t **node, unsigned int value)
{
	stack_t *head;
	int len = 0, tmp;

	head = *node;

	while (head)
	{
		head = head->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", value);
		fclose(global.file);
		free(global.line);
		free_head(*node);
		exit(EXIT_FAILURE);
	}
	head = *node;
	tmp = head->n;
	head->n = head->next->n;
	head->next->n = tmp;
}
