#include "monty.h"
#include <stdio.h>

void proc_file(char *filename)
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
	for (line_number = 1; get_line != -1; line_number++)
	{
		format = sper_line(line, line_number, format);
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

	get_func(opcode, val, line_number, format);
	return (format);
}

/**
 * get_func - get the appropriate function for the opcode
 * @opcode: opcode
 * @val: argument of the opcode
 * @format:  storage format. If 0 Nodes will be entered as a stack.
 * @line_number: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */

void get_func(char *opcode, char *value, int line_number, int format)
{
	int j;
	int mark;

		instruction_t func_arr[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
		};

	if (opcode[0] == '#')
		return;

	for (mark = 1, j = 0; func_arr[j].opcode != NULL; j++)
	{
		if(strcmp(opcode, func_arr[j].opcode) == 0)
		{
			run_fun(func_arr[j].f, opcode, value, line_number, format);
			mark = 0;
		}
	}

	if (mark == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
}
