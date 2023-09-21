#include "monty.h"
void free_head(stack_t *node)
{
	stack_t *tmp;

	tmp = node;

	while (node != '\0')
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

void f_head(stack_t **node, unsigned int value)
{
	(void)node;
	(void)value;

	global.m = 0;
}
