#include "monty.h"

void addnode(stack_t **node, int n)
{
	stack_t *new_node, *tmp;

	tmp = *node;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = new_node;

	new_node->n = n;
	new_node->next = *node;
	new_node->prev = NULL;
	*node = new_node;
}
