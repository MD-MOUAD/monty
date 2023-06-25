#include "monty.h"
/**
 * execute_line - execute founded line in the stream
 * @opcode: the opcode
 *
 * Return: 0 if success otherwise return EXIT_FAILURE
 */
int execute_line(char *opcode)
{
	int i;

	if (opcode[0] == '#')
		return (EXIT_SUCCESS);
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
