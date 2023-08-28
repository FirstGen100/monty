#include "monty.h"
/**
 * read_file - read contents of a file
 * @fp: file
 * Return: pointer to buffer store
 */
char *read_file(int fp)
{
	int buffer_size = 64;
	int dir;
	char *ret, *temp;

	ret = malloc(sizeof(char) * buffer_size);
	if (ret == NULL)
		return (NULL);
	ret = memset(ret, 0, buffer_size);
	dir = read(fp, ret, buffer_size);
	if (dir == -1)
	{
		free(ret);
		return (NULL);
	}
	while (dir == buffer_size)
	{
		buffer_size += buffer_size;
		temp = malloc(sizeof(char) * buffer_size);
		if (temp == NULL)
		{
			free(ret);
			return (NULL);
		}
		temp = memset(temp, 0, buffer_size);
		strncpy(temp, ret, (buffer_size / 2));
		free(ret);
		ret = temp;
		dir += read(fp, ret + buffer_size / 2, buffer_size / 2);
		if (dir == -1)
			return (NULL);
	}
	return (ret);
}
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

