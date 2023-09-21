#include "monty.h"


int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *n = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, file))
	{
		line_number++;
		release(&file, &line, 's');
		if (line_number != '\0')
			free(global.argument);
		global.argument = format_line(line);
		if (global.argument == NULL || (global.argument[0][0] == '\n' || global.argument[0][0] == '#'))
			continue;
		else
			get_op_function(&n, line_number);
	}
	release(NULL, NULL, 'r');
	free(global.argument);
	free_dlistint(n);
	return (EXIT_SUCCESS);
}
