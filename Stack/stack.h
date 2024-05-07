#ifndef __STACK_H__
#define __STACK_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
    struct t_node *next;
    void *data;
}t_node;

typedef struct t_stack
{
    t_node *top;
}t_stack;

t_node* init_node(void* data);
void init_stack(t_stack *stk);
int is_stack_empty(t_stack *stk);
void push(t_stack *stk, void *data);
void* pop(t_stack *stk);
void print_stack(t_stack *stk);

#endif