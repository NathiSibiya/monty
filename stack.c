#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - frees stack_t
 * @stack: pointer to top (stack) or bottom (queue) of stack_t
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * init_stack - initialises stack_t stack with beginning stack
 * @stack: pointer to an unitialised stack_t stack
 *
 * Return: if error - EXIT_FAILURE, else - EXIT_SUCCESS
 */
int init_stack(stack_t **stack)
{
	stack_t *s;

	s = malloc(sizeof(stack_t));
	if (s == NULL)
		return (malloc_error());

	s->n = STACK;
	s->prev = NULL;
	s->next = NULL;

	*stack = s;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - checks stack or queue mode
 * @stack: pointer to top (stack) or bottom (queue)
 *
 * Return: if stack_t is stack mode - STACK (0)
 *		if stack_t is stack mode - QUEUE (1)
 *		else - 2
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}
