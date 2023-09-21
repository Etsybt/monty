#include "monty.h"

void release(FILE **file, char **line, char op)
{
	static FILE *save_stream;
	static char *save_monty;

	if (op == 's')
	{
		save_stream = *file;
		save_monty = *line;
	}
	else if (op == 'r')
	{
		free(save_monty);
		fclose(save_stream);
	}

}
