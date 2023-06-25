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
/**
 * pstr - prints the string starting at the top of the stack, followed by
 * a new line.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	while (tmp)
	{
		if (tmp->n <= 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
/**
 * rotl - rotates the stack to the top
 * (The top element of the stack becomes
 * the last one, and the second top element of the stack
 * becomes the first one)
 *
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *last;
	(void) line_number;

	first = last = *stack;
	if (*stack && (*stack)->next)
	{
		*stack = (*stack)->next; /* the head of the stack will be the second
									node that contains the 2nd top element */
		while(last->next)
			last = last->next; /* last will go to the last node */

		last->next = first; /*link the last node with the first node */
		first->next =  NULL; /* now the first node becomes the last one */
		(*stack)->prev = NULL;
	}
}
