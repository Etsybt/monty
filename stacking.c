#include "monty.h"

/**
  * stacking - adds to top of stack
  * @node: points to first node
  * @n: value
  * Return: void
  */
void stacking(stack_t **node, int n)
{
	stack_t *added, *tmp;

	tmp = *node;
	added = malloc(sizeof(stack_t));

	if (added == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (tmp)
		tmp->prev = added;

	added->n = n;
	added->next = *node;
	added->prev = NULL;
	*node = added;
}
