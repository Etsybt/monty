#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node, *sst;

	if (global.argument[1] == NULL || check_num(global.argument[1]) == -1) 
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		release(NULL, NULL, 'r');
		free_dlistint(*stack);
		free(global.argument);
		exit(EXIT_FAILURE);
	}
	sst = *stack;
	new_node = malloc(sizeof(stack_t));

	 if (!new_node)
	 {
		 fprintf(stderr, "Error: malloc failed\n");
		 release(NULL, NULL, 'r');
		 free_dlistint(*stack);
		 free(global.argument);
		 exit(EXIT_FAILURE);
	 }
	 new_node->next = '\0';
	 new_node->n = atoi(global.argument[1]);
	 new_node->prev = '\0';
	 *stack = new_node;
	 new_node->next = sst;

	  if (sst)
		  (sst)->prev = new_node;
}
