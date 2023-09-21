#include "monty.h"

void queue(stack_t **node, unsigned int line_number)
{
	(void)node;
	(void)line_number;

	global.m = 1;
}

void addqueue(stack_t **node, int n)
{
	stack_t *new_node, *tmp;

	tmp = *node;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
		printf("Error\n");

	new_node->n = n;
	new_node->next = NULL;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*node = new_node;
		new_node->prev = NULL;
	}
	else
	{
		tmp->next = new_node;
		new_node->prev = tmp;
	}
}
