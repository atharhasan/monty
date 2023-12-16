#include "monty.h"

/**
 * main - main function for testing
 * @argc: number
 * @argv: function
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *filename;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		return (EXIT_FAILURE);
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
