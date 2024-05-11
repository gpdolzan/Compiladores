#include "../includes/compilador.hpp"
#include "../includes/utils/simbolos.hpp"
#include "../includes/utils/tabela_simbolos.hpp"

#include <iostream>
#include <string>

std::string simbolo_flex;
flex_simbolos relacao;
char token[TAM_SIMBOLO];
tabela_simbolos *tabela_simb;

std::ofstream mepa_stream;

std::string meu_token;

void geraCodigo(std::string comando, std::string rot, int number) {
  if (rot == "") {
    if (number == -1)
      mepa_stream << "\t" << comando << std::endl;
    else
      mepa_stream << "\t" << comando << " " << number << std::endl;
  } else {
    mepa_stream << rot << ": " << comando;
  }

  mepa_stream.flush();
}

int imprimeErro(std::string erro) {
  // fprintf(stderr, "Erro na linha %d - %s\n", nl, erro);
  // exit(-1);
  return 1;
}

void iniciaCompilador() {
  mepa_stream.open("mepa.txt", std::ofstream::out);
  tabela_simb = iniciar_tabela();
}

void desligaCompilador() {}

void insereSimbolo(Simbolo *simb) { push(tabela_simb, simb); }

Simbolo *buscaSimbolo(char *simb) {
  t_node *current = tabela_simb->top;

  while (current != NULL) {
    if (current->simbolo->identificador == simb) {
      return current->simbolo;
    }
    current = current->prev;
  }
  return NULL;
}

void removeSimbolo(int quant) {
  for (int i = 0; i < quant; i++) {
    pop(tabela_simb);
  }
}

void aplicarOperacao(char *op, tipo_variavel variavel) {
  Simbolo *s = buscaSimbolo(op);
  if (s == NULL) {
    imprimeErro("Variável não declarada");
  }
  if (s->tipo_v != variavel) {
    imprimeErro("Tipo de variável incompatível");
  }
  if (s->tipo_v == t_int) {
    geraCodigo(op);
  } else {
    geraCodigo(op);
  }
}

void visualizaTabela() { print_tabela(tabela_simb); }
