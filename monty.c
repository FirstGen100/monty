#include "monty.h"
var_t *variables = NULL;
/**
 * main - start of the programme
 * @argc: argument count
 * @argv: arguments
 * Return: 0(success)
 */
int main(int argc, char *argv[])
{
	int fp, res;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = open(argv[1], O_RDONLY);
	if (fp == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	variables = malloc(sizeof(var_t));
	if (variables == NULL)
	{
		close(fp);
		fprintf(stderr, "Error: malloc failed\n)");
		exit(EXIT_FAILURE);
	}
	variables->temp = NULL;
	variables->check = NULL;
	variables->i_temp = 0;
	variables->temp = read_file(fp);
	res = execute(variables->temp, &stack);
	if (res == 0)
	{
		free(variables->temp);
		free_stack(stack);
		free(variables);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	close(fp);
	free_stack(stack), free(variables->temp), free(variables);
	return (0);
}
/**
 * execute - executes the commands given
 * @input: string command
 * @stack: pointer to stack
 * Return: 1(success)
 */
int execute(char *input, stack_t **stack)
{
	unsigned int token = 0, i, j = 0, num = 1, flag = 0, lnum = 0, tokenlen = 0;
	char *tok;
	instruction_t inst[] = {
		{"push", push}, {"pall", pall}, {"pop", pop},
		{"nop", nop}, {NULL, NULL},
	};

	for (tokenlen = 0; input[tokenlen] == '\n'; tokenlen++)
		lnum++;
	tok = strtok(input, "\n");
	while (tok)
	{
		for (i = 0; tok[i] == ' '; i++)
			;
		if (check_comments(&lnum, i, &tok))
			continue;
		for (token = i; tok[token] && tok[token] != ' '; token++)
			;
		variables->check = check_op(tok + i, token - i);
		if (!variables->check)
			return (0);
		for (j = 0; inst[j].opcode; j++)
		{
			if (!strcmp(variables->check, "push"))
			{
				for (; tok[token] && tok[token] == ' '; token++)
					;
				if (!tok[token])
					free_exit(*stack, num + lnum, "L%u: usage: push integer\n");
				check_push(token, tok, *stack, num + lnum);
				variables->i_temp = ((variables->i_temp * 10) + atoi(tok + tokenlen));
			}
			if (!strcmp(variables->check, inst[j].opcode))
				inst[j].f(stack, num + lnum), flag = 1;
		}
		if (inst[j].opcode == NULL && !flag && *(variables->check))
			free_exit_i(*stack, num + lnum, "L%u: unknown instruction %s\n");
		lnum += num_count(tok), tok = strtok(NULL, "\n"), variables->i_temp = 0, num++, flag = 0;
	       	free(variables->check);
	}
	return (num + lnum);
}
/**
 * free_exit_i - frees and exit with a message
 * @stack: pointer to stack
 * @count: line no
 * @msg: message to print
 * Return: void
 */
void free_exit_i(stack_t *stack, unsigned int count, char *msg)
{
	fprintf(stderr, msg, count, variables->check);
	free(variables->temp);
	free(variables->check);
	free(variables);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * free_exit - free and exit wth message
 * @stack: pointer to stack
 * @count: line number
 * @msg: message
 * Return: void
 */
void free_exit(stack_t *stack, unsigned int count, char *msg)
{
	fprintf(stderr, msg, count);
	free(variables->temp);
	free(variables->check);
	free(variables);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
/**
 * num_count - count the bew lines
 * @tok: pointer to token
 * Return: number of lines
 */
int num_count(char *tok)
{
	int tokenlen, i, lnum = 0;

	for (tokenlen = 0; tok[tokenlen]; tokenlen++)
		;
	for (i = 1; tok[tokenlen + i] == '\n'; i++)
		lnum++;
	return (lnum);
}

