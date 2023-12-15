#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **new_node, unsigned int line)
{
    
    stack_t *ptr;

    (void)line;
    
    if (new_node == NULL || *new_node == NULL)
        exit(EXIT_FAILURE);
    
    if (head == NULL)
    {
        head = *new_node;
        return;
    }

    ptr = head;
    head = *new_node;
    head->next = ptr;
    ptr->prev = head;
}