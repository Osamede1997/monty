#ifndef MONTY
#define MONTY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define UNUSED(x) (void)(x)
#define TRUE 1
#define FALSE 0
#define DELIMS "\n \t\r"
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stackk_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stackk_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glob_s - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction struct
**/
typedef struct glob_s
{
	stackk_t **top;
	instruction_t **ops;
} glob_t;

extern glob_t glob;

/* monty.c */
void stack_init(stackk_t **head);
void free_all(void);

/* helper1.c */
int process_file(char *filename, stackk_t **stack);

/* helper2.c */
void delegate_op(stackk_t **stack, char *op, unsigned int line_number);

/* instruction1.c */
void instruction_push(stackk_t **stack, unsigned int line_number);
void instruction_pop(stackk_t **stack, unsigned int line_number);
void instruction_pint(stackk_t **stack, unsigned int line_number);
void instruction_pall(stackk_t **stack, unsigned int line_number);
void instruction_swap(stackk_t **stack, unsigned int line_number);

/* instruction2.c */
void instruction_add(stackk_t **stack, unsigned int line_number);
void instruction_nop(stackk_t **stack, unsigned int line_number);
void instruction_sub(stackk_t **stack, unsigned int line_number);
void instruction_div(stackk_t **stack, unsigned int line_number);
void instruction_mul(stackk_t **stack, unsigned int line_number);

/* instruction3.c */
void instruction_mod(stackk_t **stack, unsigned int line_number);
void instruction_pchar(stackk_t **stack, unsigned int line_number);
void instruction_pstr(stackk_t **stack, unsigned int line_number);
void instruction_rotl(stackk_t **stack, unsigned int line_number);
void instruction_rotr(stackk_t **stack, unsigned int line_number);

/* _strtol.c */
int is_leading_digit(char ascii_char);
int _strtol(char *num_string, unsigned int line_number);

#endif /* MONTY */
