#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line)
{
    char *value_str;
    int value;
    stack_t *new_node;
    
    value_str = strtok(NULL, " ");
    if (value_str == NULL || !isInteger(value_str) )
    {
        fprintf(stderr, "L%u: usage: push integer\n", line);
        exit(EXIT_FAILURE);
    }
    value = atoi(value_str);

    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
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
    }
    else
    {
        new_node->next = *stack;
        (*stack)->prev = new_node;
        *stack = new_node;
    }
}


int isInteger(char *str)
{
    if (*str == '-' || *str == '+') {
        str++;
    }
    while (*str != '\0') {
        if (*str < '0' || *str > '9') {
            return 0;
        }
        str++;
    }
    return 1;
}
