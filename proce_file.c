#include "monty.h"

/**
 * proc_file - the way we deal with the functions
 * @filename: the file taken from the user
 * @stack: Something I didn't get clearly
*/

void proc_file(char *filename, stack_t **stack)
{
	char *line = NULL;
	char *opcode;
	size_t len = 0;
	unsigned int line_number = 0;
	FILE *file = fopen(filename, "r");

	if (file == NULL || filename == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		line[strcspn(line, "\n")] = '\0';
		opcode = strtok(line, " ");
		if (opcode != NULL)
		{
			if (strcmp(opcode, "push") == 0)
				push(stack, line_number);
			else if (strcmp(opcode, "pall") == 0)
				pall(stack, line_number);
			else if (strcmp(opcode, "pint") == 0)
				pint(stack, line_number);
			else if (strcmp(opcode, "pop") == 0)
				pop(stack, line_number);
			else if (strcmp(opcode, "swap") == 0)
				swap(stack, line_number);
			else if (strcmp(opcode, "add") == 0)
				add(stack, line_number);
			else if (strcmp(opcode, "nop") == 0)
				nop(stack, line_number);
			else
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	free(line);
	fclose(file);
}

/**
 * sper_line - Put each line into token
 * @line: line
 * @line_number: line number
 * @format: storage format. If 0 Nodes will be entered as a stack.
 * if 1 nodes will be entered as a queue.
 * Return: Returns same as Format
 */
int sper_line(char *line, int line_number, int format)
{
	char *opcode, *val;
	const char *delim = "\n ";

	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	opcode = strtok(line, delim);
	if (opcode == NULL)
		return (format);
	val = strtok(NULL, delim);

	if (strcmp(opcode, "push") == 0)
		return (0);
	if (strcmp(opcode, "pall") == 0)
		return (1);

	get_func(opcode, val, line_number);
	return (format);
}

/**
 * get_func - get the appropriate function for the opcode
 * @opcode: opcode
 * @value: argument of the opcode
 * @line_number: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void get_func(char *opcode, char *value, int line_number)
{
	int j;
	int mark;

	instruction_t func_arr[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{NULL, NULL}};

	if (opcode[0] == '#')
		return;
	printf("DEBUG: Trying to match opcode '%s'\n", opcode);

	for (mark = 1, j = 0; func_arr[j].opcode != NULL; j++)
	{
		if (strcmp(opcode, func_arr[j].opcode) == 0)
		{
			run_fun(opcode, value, line_number);
			mark = 0;
		}
	}

	if (mark == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
