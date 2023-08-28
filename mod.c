#include "monty.h"

/**
 * stk_sub - subtracts the top element of stack from the second element
 * @stack: head to the st
 * *@line_number:file line execution
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't sub, stack too short\n", line_number);
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	temp->n = temp2->n - temp->n;
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_div - divides the second top element of stack from the top element
 * @stack: head to the stack
 *@line_number:file line execution
 */

void div(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *temp2;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't div, stack too short\n", line_number);
		return;
	}
	temp = (*stack);
	temp2 = temp->next;
	if (temp->n == 0)
	{
		printf("L%d: division by zero\n", line_number);
		return;
	}

	temp->n = (int)(temp2->n / temp->n);
	temp->next = temp2->next;
	if (temp2->next != NULL)
		temp2->next->prev = temp;
	else
		temp->next = NULL;
	free(temp2);
}

/**
 * stk_mul - multiplies the top two elements of the stack
 * @stack: head to the stack
 * @line_number: file line execution
 */

void mul(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n",
			line_number);
		free(stack);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n * (*stack)->n;
	pop(stack, line_number);
}
/**
 * stk_mod - divides second top element by top element and gets remainder
 * @stack: head to the stack
 * @line_number:file line execution
 */

void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *curerent = NULL;
	int div = 0;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	curerent = *stack;
	div = curerent->next->n % curerent->n;
	curerent->next->n = div;
	pop(stack, line_number);
}
