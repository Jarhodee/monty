#include "monty.h"

void f_pall(stack_t **head, unsigned int counters)
{
	stack_t *h;
	(void)counters;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
