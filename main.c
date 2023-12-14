#include "monty.h"

/**
 * main - main function for testing
 */
int main(int argc, char *argv[])
{
    stack_t *stack = NULL;
    const char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    proc_file(filename, &stack);

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return (0);
}