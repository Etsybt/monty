#include "monty.h"

#define _GNU_SOURCE

global_data_t global = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *node = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	global.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line(file, &line, &len))
	{
		line = NULL;
		/* read_line = getline(&line, &len, file); */
		global.line = line;
		line_number++;

		if (global.line != NULL)
			operate(global.line, &node, line_number, file);

		free(line);
	}
	free_head(node);
	fclose(file);
	return (0);
}
