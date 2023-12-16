#include "monty.h"

/**
 * run_fun - Runs the required function.
 * @op: string of the opcode.
 * @val: A numeric value string
 * @ln: line numeber
 * 1 for a queue.
 */

void run_fun(char *op, char *val, int ln)
{
	int i;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
		}
		if (val == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
		}
	}
}
