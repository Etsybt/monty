#include "monty.h"

/**
  * free_head - free linked lists
  * @node: first node
  * Return: void
  */
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

/**
  * frees_head - frees head
  * @node: unused
  * @value: unused
  * Return: void
  */

void frees_head(stack_t **node, unsigned int value)
{
	(void)node;
	(void)value;

	global.m = 0;
}
