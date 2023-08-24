#include "monty.h"

void f_push(stack_t **head, unsigned int counters)
{
	int n, jx = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			jx++;
		for (; bus.arg[jx] != '\0'; jx++)
		{
			if (bus.arg[jx] > 57 || bus.arg[jx] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counters);
			fclose(bus.file);
			free(bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counters);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}