#include "monty.h"
/**
 * main - start of the programme
 * @argc: argument count
 * @argv: arguments
 * Return: 0(success)
 */
int main(int argc, char *argv[])
{
	FILE *fp;
	char *input, *file, *buffer = NULL;
	unsigned int count = 0;
	size_t buffer_size = 0;
	stack_t *stack;

	file = argv[1];
	if (argc < 2)
	{
		fprintf(stderr, "USAGE: monty <file>\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(file, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buffer_size, fp) != -1)
	{
		input = strtok(buffer, "\n");
		get_tokens(input, &stack, count);
		count++;
	}
	fclose(fp);
	free(buffer);
	if (stack != NULL)
		free_stack(&stack, count);

	return (EXIT_SUCCESS);
}
/**
 * get_tokens - split user input
 * @input: user input
 * @stack: pointer to the stack
 * @count: number of lines in file
 * Return: array of input
 */
void get_tokens(char *input, stack_t **stack, unsigned int count)
{
	char *token, *tokens;

	token = strtok(input, " ");
	if (token == NULL || *token == ' ' || *token == '\n' || *token == '#')
		return;
	if (strcmp(token, "push") == 0)
	{
		tokens = token;
		token = strtok(NULL, " ");
		if (!is_num(token))
		{
			count++;
			fprintf(stderr, "L%d: usage: push integer\n", count);
			free_stack(stack, count);
			exit(EXIT_FAILURE);
		}
		variables.temp = atoi(token);
		find_operation(tokens, stack, count);
	}
	else
		find_operation(token, stack, count);
}
/**
 * is_num - check for integers
 * @token: user string
 * Return: 1(int)
 */
int is_num(char *token)
{
	if (token == NULL)
		return (0);
	if (*token != '\0')
	{
		if (!isdigit(*token))
			return (0);
		token++;
	}
	token++;
	return (1);
}
/**
 * find_operation - find the needed operation
 * @token: User command
 * @stack: pointer to stack
 * @count: counter variable
 * Return: void
 */
void find_operation(char *token, stack_t **stack, unsigned int count)
{
	int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};

	while (op[i].opcode != NULL)
	{
		if (strcmp(token, op[i].opcode) == 0)
		{
			op[i].f(stack, count);
			return;
		}
		i++;
	}
	count++;
	fprintf(stderr, "L%d: unknown instruction %s\n", count, token);
	free_stack(stack, count);
	exit(EXIT_FAILURE);
}
/**
 * free_stack - free the stack
 * @stack: pointer to the stack
 * @count: counter var
 * Return: void
 */
void free_stack(stack_t **stack, unsigned int count)
{
	if (stack == NULL)
		return;
	while (*stack != NULL)
		pop(stack, count);
}

