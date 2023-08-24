#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct var - temporary variable and check
 * @temp: temporary variable
 * @check: check for var
 */
typedef struct var
{
	int temp;
	char check;
} var_t;
extern var_t variables;
var_t variables;
/* operation functions */

/* ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/
void get_tokens(char *input, stack_t **stack, unsigned int count);
int is_num(char *input);
void find_operation(char *token, stack_t **stack, unsigned int count);
void free_stack(stack_t **stack, unsigned int count);
/* stack fuctions */
void push(stack_t **stack, unsigned int count);
void pall(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int count);

#endif /* MONTY_H */

