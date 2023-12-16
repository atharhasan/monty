#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line)
{
    char *value_str;
    char *endptr;
    int value;
    stack_t *new_node;

    value_str = strtok(NULL, " ");
    if (value_str == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }

    value = strtol(value_str, &endptr, 10);

    if (*endptr != '\0' && !isspace((unsigned char)*endptr))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL )
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*stack == NULL)
    {
        *stack = new_node;
        return;
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}
