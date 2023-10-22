#include "monty.h"

int short_stack_error(unsigned int line_number, char *op);
int div_error(unsigned int line_nubmber);
int pop_error(unsigned int line_number);
int pchar_error(unsigned int line_number, char *messsage);

/**
 * pop_error - prints pop error meassage for empty stacks
 * @line_number: line number in script where error occured
 *
 * Return: (EXIT_FAILURE) always
 */
int pop_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pint_error - prints pint error messages for empty stacks
 * @line_number: line number in monty bytecodes
 *
 * Return: (EXIT_FAILURE)
 */
int pint_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * short_stack_error - prints monty ath function error messages
 *			for stacks/queues smaller than 2 nodes
 * @line_number: line number in monty bytecodes
 * @op: oparation where error occured
 *
 * Return: (EXIT_FAIURE)
 */
int short_stack_error(unsigned int line_number, char *op)
{
	fprintf(stderr, "L%u: can't %s, stack too short\n", line_number, op);
	return (EXIT_FAILURE);
}

/**
 * div_error - print division error messages for div by 0
 * @line_number: line number in monty bytecodes
 *
 * Return: (EXIT_FAILURE)
 */
int div_error(unsigned int line_number)
{
	fprintf(stderr, "L%u: division by zero\n", line_number);
	return (EXIT_FAILURE);
}

/**
 * pchar_error - prints pchar error messages for empty stacks and non character
 * @line_number: line number in monty bytecodes
 * @message: corresponding error message
 *
 * Return: (EXIT_FAILURE)
 */
int pchar_error(unsigned int line_number, char *message)
{
	fprintf(stderr, "L%u: can't pchar, %s\n", line_number, message);
	return (EXIT_FAILURE);
}
