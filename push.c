#include "monty.h"

void push(stack_t **node, unsigned int value)
{
	int x, y = 0, bit = 0;

	if (global.argument)
	{
		if (global.argument[0] == '-')
			y++;
		for (; global.argument[y] != '\0'; y++)
		{
			if (global.argument[y] > 57 || global.argument[y] < 48)
				bit = 1;
		}
		if (bit == 1) 
		{
			fprintf(stderr, "L%d: usage: push integer\n", value);
			fclose(global.file);
			free(global.argument);
			free_head(*node);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", value);
		fclose(global.file);
		free(global.line);
		free_head(*node);
		exit(EXIT_FAILURE);
	}
	x = atoi(global.argument);

	if (global.m == 0)
		addnode(node, x);
	else
		addqueue(node, x);
}
