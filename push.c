#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to the stack
 * @line_number: line number in the file
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *value_str;
    int value;
    stack_t *new_node;

    /*Assume that the opcode is already checked before calling this function*/
    value_str = strtok(NULL, " ");
    if (value_str == NULL)
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    value = atoi(value_str);

    /* Create a new node*/
    new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    /* Initialize the new node*/
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    /* Update the previous node if the stack is not empty*/
    if (*stack != NULL)
        (*stack)->prev = new_node;

    /* Update the stack pointer*/
    *stack = new_node;
}