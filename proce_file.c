#include "monty.h"
#include <stdio.h>

void proc_file(const char *filename, stack_t **stack)
{
	char *line = NULL;
	size_t len = 0;
	int get_line;
	int line_number, format = 0;
	FILE *file = fopen(filename, "r");

	if (file == NULL || filename == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	get_line = getline(&line, &len, file);
	while (get_line != -1)
	{
		line_number++;
		format = sper_line(line, line_number, format, stack);
	}

	/* Clean up (free memory)*/
	free(line);
}

/**
 * sper_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line_number: line number
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
int sper_line(char *line, int line_number, int format, stack_t **stack)
{
	char *opcode;
	const char *delim = "\n ";

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(line, delim);
	if (opcode == NULL)
		return (format);
	/*value = strtok(NULL, delim);*/

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
	return (format);
}