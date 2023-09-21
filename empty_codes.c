#include "monty.h"

int empty_codes(char **string)
{
	int i = 0;

	while (string[0][i] != '\0')
	{
		if (string[0][i] != ' ')
			return (-1);
		i++;
	}
	return (1);
}

