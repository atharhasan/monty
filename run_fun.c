#include "monty.h"

/**
 * run_fun - Runs the required function.
 * @func: Pointer to the function
 * @op: string of the opcode.
 * @val: A numeric value string
 * @ln: line numeber
 * @format: Format specifier. 0 for a stack.
 * 1 for a queue.
 */

void run_fun(op_func func, char *op, char *val, int ln)
{
	/*stack_t *node;
	int flag  = 1;*/
	int i;

	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			/*flag = -1;*/
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
		/*node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}*/
	else
		func(&head, ln);
}
