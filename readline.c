#include "monty.h"

int read_line(FILE *file, char **line, size_t *len)
{
	ssize_t read = getline(line, len, file);
	if (read == -1)
	{
		return 0;
	}
	return 1;
}
