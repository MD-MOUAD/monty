#include "monty.h"
/**
 *
 *
 *
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *number;

	number = strtok(NULL, " \t\n");
	if (number == NULL || _isdigit(number) == EXIT_FAILURE)
	{
		fprintf(stderr, "L<%d>: usage: push integer\n", line_number);
		fclose(vars.stream);
		free_all();
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(vars.stream);
		free_all();
		exit(EXIT_FAILURE);
	}
	new->n = atoi(number);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
/**
 *
 *
 *
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void) line_number;

	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}
