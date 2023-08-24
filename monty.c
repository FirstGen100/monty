#include "monty.h"
/**
 * main - start of the programme
 * @argc: argument count
 * @argv: arguments
 * Return: 0(success)
 */
int main(int argc, char **argv[])
{
	FILE *fp;
	char *input, *file, *buffer = NULL;
	unsigned int count = 0;
	size_t buffer_size = 0;
	stack_t *stack;

	file = argv[1];
	if (argc < 2)
	{
		fprinf(stderr, "USAGE: monty <file>\n");
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
		free(&stack, count);

	return(EXIT_SUCCESS);
}
/**
 * get_tokens - split user input
 * @input: user input
 * @stack: pointer to the stack
 * @count: number of lines in file
 * Return: array of input
 */
char *get_tokens(char *input, stack_t stack, unsigned int count)
