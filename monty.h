#ifndef _MONTY_H_
#define _MONTY_H_
#define  _GNU_SOURCE
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_numbers);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(stack_t **head, unsigned int numbers);
void f_pall(stack_t **head, unsigned int numbers);
void f_pint(stack_t **head, unsigned int numbers);
int execute(char *content, stack_t **head, unsigned int counters, FILE *file);
void free_stack(stack_t *head);
void f_pop(stack_t **head, unsigned int counters);
void f_swap(stack_t **head, unsigned int counters);
void f_add(stack_t **head, unsigned int counters);
void f_nop(stack_t **head, unsigned int counters);
void f_sub(stack_t **head, unsigned int counters);
void f_div(stack_t **head, unsigned int counters);
void f_mul(stack_t **head, unsigned int counters);
void f_mod(stack_t **head, unsigned int counters);
void f_pchar(stack_t **head, unsigned int counters);
void f_pstr(stack_t **head, unsigned int counters);
void f_rotl(stack_t **head, unsigned int counters);
void f_rotr(stack_t **head, __attribute__((unused)) unsigned int counters);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void f_queue(stack_t **head, unsigned int counters);
void f_stack(stack_t **head, unsigned int counters);

#endif
