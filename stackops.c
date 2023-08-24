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

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: unknown  stack\n", count);
		exit(EXIT_FAILURE);
	}
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: memory allocation failure\n");
		free_stack(stack, count);
		exit(EXIT_FAILURE);
	}
	new_node->n = variables.temp;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack != NULL)
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
	stack_t *temp;
	(void)count;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
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
		count++;
		fprintf(stderr, "L%d: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		*stack = (*stack)->next;
		variables.temp = (*stack)->n;
		free((*stack)->prev);
		(*stack)->prev = NULL;
	}
	else
	{
		free(*stack);
		*stack = NULL;
	}
}

