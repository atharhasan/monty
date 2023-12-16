#include "monty.h"

/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void) line_number;

	if (current == NULL)
		exit(EXIT_FAILURE);

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
