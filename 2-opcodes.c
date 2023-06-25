#include "monty.h"
/**
 * mod - computes the rest of the division of the second top element of
 * the stack by the top element of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next || (*stack)->n == 0)
	{
		if (*stack && (*stack)->next)
			fprintf(stderr, "L%u: division by zero\n", line_number);
		else
			fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		free_all(), fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n = (*stack)->next->n % (*stack)->n;
		pop(stack, line_number);
	}
}
#include "monty.h"
/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all(), fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		free_all(), fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
