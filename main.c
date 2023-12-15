#include "monty.h"
stack_t *head = NULL;

/**
 * main - main function for testing
 */
int main(int argc, char *argv[])
{
    char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    proc_file(filename);
	
    while (head != NULL)
    {
        stack_t *temp = head;
        head = head->next;
        free(temp);
    }

    return (0);
}

