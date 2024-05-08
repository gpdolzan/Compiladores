#ifndef __STACK_H__
#define __STACK_H__

#include "simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t_node {
  struct t_node *next;
  struct t_node *prev;

  simbolo *simbolo;
} t_node;

typedef struct tabela_simbolos {
  t_node *top;
  t_node *bottom;
} tabela_simbolos;

tabela_simbolos *iniciar_tabela();
int is_stack_empty(tabela_simbolos *tabela);
void push(tabela_simbolos *tabela, simbolo *simbolo);
void coloca_tipo_em_simbolos(tabela_simbolos *tabela, tipo_variavel tipo, int quantidade);
simbolo *busca_simbolo(tabela_simbolos *tabela, char* simb);
simbolo *pop(tabela_simbolos *tabela);
void print_simbolo(simbolo *s);
void print_tabela(tabela_simbolos *tabela);

#endif