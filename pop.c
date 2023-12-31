#include "monty.h"
/**
  * pop - removes the top element of the stack.
  * @node: first node
  * @value: counts lines
  * Return: void
  */
void pop(stack_t **node, unsigned int value)
{
	stack_t *head;

	if (*node == '\0')
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", value);
		fclose(global.file);
		free(global.line);
		free_head(*node);
		exit(EXIT_FAILURE);
	}
	head = *node;
	*node = head->next;
	free(head);
}
