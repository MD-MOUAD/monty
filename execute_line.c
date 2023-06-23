#include "monty.h"
Data vars;
/**
 *
 */
int execute_line(char *opcode)
{
	int i;

	for (i = 0; vars.instruct[i].opcode; i++)
	{
		if (strcmp(vars.instruct[i].opcode, opcode) == 0)
		{
			vars.instruct[i].f(&vars.stack, vars.line_number);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
