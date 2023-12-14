#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **ptr, unsigned int line)
{
    char *value_str;
    int value;
    stack_t *new_node;

    value_str = strtok(NULL, " ");
    value = atoi(value_str);

    if (value_str == NULL || value < 1)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }

    /* Create a new node*/
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (ptr == NULL)
    {
        /* Initialize the new node*/
        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *ptr;
    }
    else
    {
        (*ptr)->prev = new_node;
        *ptr = new_node;
    }

    /* Update the previous node if the stack is not empty
    if (*stack != NULL)
        (*stack)->prev = new_node;

    Update the stack pointer
    *stack = new_node;*/
}