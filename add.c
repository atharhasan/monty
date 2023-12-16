#include "monty.h"

/**
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

/**
 * nop - Does nothing.
 * @stack: pointing to top node of the stack.
 * @line_number: number of of the opcode line as an Integer.
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
