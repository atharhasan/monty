#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current;

    (void) line_number;
    if (stack == NULL)
        exit(EXIT_FAILURE);
    current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}