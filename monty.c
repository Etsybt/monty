#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE

#include "monty.h"

global_data_t global = {NULL, NULL, NULL, 0};

/**
  * main - main func
  * @ac: argument count
  * @av: pointer
  * Return: 0
  */
int main(int ac, char *av[])
{
	char *line;
	FILE *file = NULL;
	size_t len = 0;
	ssize_t read_line = 1;
	stack_t *node = NULL;
	unsigned int line_number = 0;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(av[1], "r");
	global.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &len, file);
		global.line = line;
		line_number++;

		if (read_line > 0)
			operate(line, &node, line_number, file);

		free(line);
	}
	free_head(node);
	fclose(file);
	return (0);
}
