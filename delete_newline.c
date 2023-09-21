#include "monty.h"

void delete_newline(char **delete)
{
	int i = 0;
	char *string = *delete;

	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			string[i] = '\0';
		i++;
	}
}
