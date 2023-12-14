#include "monty.h"



/**
 * main - main function for testing
 */
int main(int argc, char *argv[])
{
    const char *filename;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }

    filename = argv[1];
    proc_file(filename);

    return (0);
}