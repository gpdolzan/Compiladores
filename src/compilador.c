#include "compilador.h"
#include "utils/tabela_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

flex_simbolos simbolo_flex, relacao;
char token[TAM_SIMBOLO];
tabela_simbolos *tabela_simb;

FILE *fp = NULL;

void geraCodigo(char *rot, char *comando, int number = -1) {
  if (fp == NULL) {
    fp = fopen("MEPA", "w");
  }

  if (rot == NULL) {
    fprintf(fp, "     %s\n", comando);
    fflush(fp);
  } else {
    fprintf(fp, "%s: %s \n", rot, comando);
    fflush(fp);
  }

  if (number != -1) {
    fprintf(fp, " %d\n", number);
    fflush(fp);
  }
}

int imprimeErro(char *erro) {
  fprintf(stderr, "Erro na linha %d - %s\n", nl, erro);
  exit(-1);
}

void iniciaCompilador() {
  tabela_simb = iniciar_tabela();
}

void desligaCompilador() {}

void insereSimbolo(simbolo *simb) {
  push(tabela_simb, simb);
}

simbolo *buscaSimbolo(char *simb) {
  t_node *current = tabela_simb->top;
  
  while (current != NULL) {
    if (strcmp(current->simbolo->simbolo, simb) == 0) {
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