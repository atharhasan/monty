#include "monty.h"
/**
 * pall - prints all the values on the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void pall(stack_t **stack)
{
    stack_t *current = *stack;

    if (current == NULL)
        return;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}