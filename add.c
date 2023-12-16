#include "monty.h"

/*
 * add - adds the top two elements of the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *stack;
	top2 = top1->next;

	top2->n += top1->n;
	*stack = top2;
	top2->prev = NULL;
	free(top1);
}