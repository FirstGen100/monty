#include "monty.h"

/**
 * _push - pushes an element to the stack
 *
 * @doubly: head of the linked list
 *@count: counter var
 * Return: no return
 */
void push(stack_t **stack, int count)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    
    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    
    if (*stack)
        (*stack)->prev = new_node;
    
    *stack = new_node;
}
/**
 * pop - remove item from top of stack
 * @stack: pointer to stack
 * @count: counter variable
 * Return: void
 */
void pop(stack_t **stack, unsigned int count)
{
	int result;

	result = delete_stack_head(stack);
	if (result != 1)
	{
		printf("L%d: can't pop an empty stack\n", count);
		value[2] = 1;
		return;
	}
}
/**
 * pall - prints the stack
 * @stack: pointer to the stack
 * @count: counter variable
 * Return: void
 */
void pall(stack_t **stack, unsigned int count)
{
    stack_t *current = *stack;
    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
