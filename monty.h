#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
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
 * @i_temp: temp integer for push
 * @check: check for var
 */
typedef struct var
{
	char *temp;
	int i_temp;
	char *check;
} var_t;
extern var_t *variables;
var_t *variables;
/* operation functions */
char *read_file(int fp);
void check_push(int tokenlen, char *token, stack_t *stack, int count);
bool check_comments(unsigned int *count, int i, char **token);
int execute(char *input, stack_t **stack);
void free_exit_i(stack_t *stack, unsigned int count, char *msg);
void free_exit(stack_t *stack, unsigned int count, char *msg);
int num_count(char *token);
char *check_op(char *token, int tok_o);
/* stack fuctions */
void push(stack_t **stack, unsigned int count);
void pall(stack_t **stack, unsigned int count);
void pop(stack_t **stack, unsigned int count);
void nop(stack_t **stack, unsigned int count);
void free_stack(stack_t *head);
size_t print_stack(const stack_t *head);

#endif /* MONTY_H */

