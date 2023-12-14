#include "monty.h"

void proc_file(const char *filename)
{
	stack_t *stack = NULL;
	char *line = NULL;
	char *opcode;
	int len = 0;
	unsigned int line_number = 0;
	char *n;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	n = fgets(line, len, file);
	while (n != NULL)
	{
		line_number++;

		/* Remove newline character*/
		line[strcspn(line, "\n")] = '\0';

		/* Tokenize the line*/
		opcode = strtok(line, " ");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
				push(&stack, line_number);
			else if (strcmp(opcode, "pall") == 0)
				pall(&stack, line_number);
			/* Add more opcode handlers as needed*/
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}

	/* Clean up (free memory)*/
	free(line);
	fclose(file);

	/* Add additional cleanup for the stack if needed*/
}