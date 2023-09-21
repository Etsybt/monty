#include "monty.h"
void free_dlistint(stack_t *head)
{
	stack_t *sst;

	if (head != '\0')
		while (head != '\0')
		{
			sst = head;
			head = head->next;
			free(sst);
		}
}
