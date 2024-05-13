#ifndef __STACK_H__
#define __STACK_H__

#include "simbolos.hpp"

class t_node {
public:
  t_node *next;
  t_node *prev;

  Simbolo *simbolo;
};

class TabelaSimbolos {
public:
  TabelaSimbolos() : top(nullptr), bottom(nullptr){};

  void push(Simbolo *simbolo);
  Simbolo *pop();
  Simbolo *busca_simbolo(const std::string &simb);

  void coloca_tipo_em_simbolos(tipo_variavel tipo, int quantidade);
  void coloca_tipo_em_simbolos(tipo_parametro_variavel tipo, int quantidade);

  void print_tabela();

protected:
  int is_stack_empty();

private:
  t_node *top;
  t_node *bottom;
};

void print_simbolo(Simbolo *s);

#endif