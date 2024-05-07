#ifndef __STACK_H__
#define __STACK_H__

#include "simbolos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct t_node {
  struct t_node *next;
  struct t_node *prev;

  simbolo *simbolo;
} t_node;

typedef struct t_stack {
  t_node *top;
  t_node *bottom;
} tabela_simbolos;

tabela_simbolos *iniciar_tabela();
// int is_stack_empty(t_stack *stk);
void push(tabela_simbolos *tabela, simbolo *simbolo);
simbolo *pop(tabela_simbolos *tabela);

// void print_stack(t_stack *tabela);

#endif