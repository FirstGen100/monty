#include "monty.h"
/**
 * push - add to the top of the stack
 * @stack: pointer to the stack
 * @count: counter var
 * Return: void
 */
void push(stack_t **stack, unsigned int count)
{
	stack_t *new_node;
	(void)count;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed.\n");
		free_stack(*stack);
		free(variables->temp);
		exit(EXIT_FAILURE);
	}
	new_node->n = variables->i_temp;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
		(*stack)->prev = new_node;
	*stack = new_node;
}
/**
 * pall - prints the stack
 * @stack: pointer to the stack
 * @count: counter variable
 * Return: void
 */
void pall(stack_t **stack, unsigned int count)
{
	(void)count;

	print_stack(*stack);
}
/**
 * print_stack - prints the stack as a doubly linked list
 * @h: pointer to start of stack
 * Return: number of nodes
 */
size_t print_stack(const stack_t *h)
{
	int i;

	if (h == NULL)
		return (0);
	for (i = 0; h; i++, h = h->next)
		printf("%d\n", h->n);
	return (i);
}
/**
 * pop - remove item from top of stack
 * @stack: pointer to stack
 * @count: counter variable
 * Return: void
 */
void pop(stack_t **stack, unsigned int count)
{
	if (stack == NULL || *stack == NULL)
	{
		free(variables->temp);
		free(variables->check);
		free(variables);
		fprintf(stderr, "L%u: Can't pop empty stsck\n", count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}
/**
 * free_stack - free the stack
 * @stack: pointer to the stack
 * Return: void
 */
void free_stack(stack_t *stack)
{
	if (stack == NULL)
		return;
	for (; stack->next; stack = stack->next)
	{
		if (stack->prev)
			free(stack->prev);
	}
	free(stack->prev);
	free(stack);
}

