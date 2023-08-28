#include "monty.h"
/**
 * check_op - initialise to operations pointer
 * @tok: pointer to start
 * @tok_o: lenght of token - number of spaces
 * Return: pointer to allocated buffer
 */
char *check_op(char *tok, int tok_o)
{
	char *ret;

	ret = malloc(sizeof(char) * (tok_o + 1));
	if (ret == NULL)
		return (NULL);
	ret = memset(ret, 0, (tok_o + 1));
	ret = strncpy(ret, tok, tok_o);
	return (ret);
}
/**
 * check_push - check if correct use of push
 * @tokenlen: index
 * @tok: pointer to the token
 * @stack: pointer to stack
 * @count: line number
 * Return: void
 */
void check_push(int tokenlen, char *tok, stack_t *stack, int count)
{
	for (; tok[tokenlen] != ' ' && tok[tokenlen]; tokenlen++)
		if ((!isdigit(tok[tokenlen]) && tok[tokenlen] != '-'))
			free_exit(stack, count, "L%u: usage: push integer\n");
}
/**
 * check_comments - check for comments
 * @count: line number
 * @i: index
 * @token: pointer to token
 * Return: true/ false
 */
bool check_comments(unsigned int *count, int i, char **token)
{
	if ((*token)[i] == '#')
	{
		*count += num_count(*token) + 1;
		*token = strtok(NULL, "\n");
		return (true);
	}
	return (false);
}

