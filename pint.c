#include "monty.h"

void pint(stack_t **node, unsigned int value)
{
	if (*node == '\0')
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", value);
		fclose(global.file);
		free(global.argument);
		free_head(*node);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}
