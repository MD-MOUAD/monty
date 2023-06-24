#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_all();
		fclose(vars.stream);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*stack)->next->n += (*stack)->n;
		pop(stack, line_number);
	}
}
/**
 * nop - adds the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void nop(stack_t **stack, unsigned int line_number)
{

}
/**
 * sub - adds the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void sub(stack_t **stack, unsigned int line_number)
{

}
/**
 * mul - adds the top two elements of the stack.
 * @stack: the head of the stack
 * @line_number: the line number where the opcode exist
 *
 * Return: (void)
 */
void mul(stack_t **stack, unsigned int line_number)
{

}
