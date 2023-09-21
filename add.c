#include "monty.h"

void add(stack_t **node, unsigned int value)
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
		fprintf(stderr, "L%u: can't add, stack too short\n", value);
		fclose(global.file);
		free(global.line);
		free_head(*node);
		exit(EXIT_FAILURE);
	}
	head = *node;
	tmp = head->n + head->next->n;
	head->next->n = tmp;
	*node = head->next;
	free(head);
}
