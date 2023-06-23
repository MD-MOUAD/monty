#include "monty.h"
/**
 *
 *
 */
void initialize_vars(void)
{
	vars.buff = NULL;
	vars.size = 0;
	vars.line_number = 1;
	vars.stack = NULL;
	vars.instruct[0].opcode = "push", vars.instruct[0].f = push;
	vars.instruct[1].opcode = "pall", vars.instruct[1].f = pall;
	vars.instruct[2].opcode = NULL, vars.instruct[2].f = NULL;
}
/**
 *
 *
 */
void free_all(void)
{
	if (vars.buff)
		free(vars.buff);
	if (vars.stack)
	{
		while (vars.stack->next)
		{
			vars.stack = vars.stack->next;
			free(vars.stack->prev);
		}
		free(vars.stack);
	}
}
/**
 *
 *
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] < 48 || str[i] > 57)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
