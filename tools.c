#include "monty.h"
/**
 * initialize_vars - initialize variables
 *
 * Return: void
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
 * free_all - free allocated memory
 *
 * Return: void
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
 * _isdigit - check if string is digit
 * @str: string to check
 *
 * Return: 0 if success otherwise return EXIT_FAILURE
 */
int _isdigit(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
			continue;
		if (str[i] < 48 || str[i] > 57)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
