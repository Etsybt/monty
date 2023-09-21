#include "monty.h"
/**
  * last - gives first node of queue
  * @node: points to first node
  * @line_number: counts lines
  * Return: void
  */
void last(stack_t **node, unsigned int line_number)
{
	(void)node;
	(void)line_number;

	global.m = 1;
}

/**
  * rev_stacking - add node to queue
  * @node: first node
  * @n: counts lines
  * Return: void
  */

void rev_stacking(stack_t **node, int n)
{
	stack_t *added, *tmp;

	tmp = *node;
	added = malloc(sizeof(stack_t));

	if (added == NULL)
		printf("Error\n");

	added->n = n;
	added->next = NULL;

	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
	}
	if (!tmp)
	{
		*node = added;
		added->prev = NULL;
	}
	else
	{
		tmp->next = added;
		added->prev = tmp;
	}
}
