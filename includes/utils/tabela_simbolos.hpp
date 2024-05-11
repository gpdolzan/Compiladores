#ifndef __STACK_H__
#define __STACK_H__

#include "simbolos.hpp"

class t_node {
public:
  t_node *next;
  t_node *prev;

  Simbolo *simbolo;
};

class tabela_simbolos {
public:
  t_node *top;
  t_node *bottom;
};

tabela_simbolos *iniciar_tabela();
int is_stack_empty(tabela_simbolos *tabela);

void print_simbolo(Simbolo *s);
void print_tabela(tabela_simbolos *tabela);

void push(tabela_simbolos *tabela, Simbolo *simbolo);
Simbolo *pop(tabela_simbolos *tabela);
void coloca_tipo_em_simbolos(tabela_simbolos *tabela, tipo_variavel tipo,
                             int quantidade);
Simbolo *busca_simbolo(tabela_simbolos *tabela, char *simb);

#endif