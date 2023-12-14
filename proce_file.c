#include "monty.h"
#include <stdio.h>


void proc_file(const char *filename)
{
	stack_t **stack = NULL;
	char *line = NULL;
	char *opcode;
	size_t len = 0;
	char *get_line;
	unsigned int line_number = 0;
	FILE *file = fopen(filename, "r");

	if (file == NULL || filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	get_line = fgets(line, len, file);
	while (get_line != NULL)
	{
		line_number++;
		/* Remove newline character*/
		line[strcspn(line, "\n")] = '\0';

		/* Tokenize the line*/
		opcode = strtok(line, " ");

		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
				push(stack, line_number);
			else if (strcmp(opcode, "pall") == 0)
				pall(stack);
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