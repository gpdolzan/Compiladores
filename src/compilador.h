#include "utils/simbolos.h"

/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

extern flex_simbolos simbolo_flex, relacao;
extern char token[TAM_SIMBOLO];
extern int nivel_lexico;
extern int desloc;
extern int nl;

/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

void geraCodigo(char *, char *);
int yylex();
void yyerror(const char *s);

void iniciaCompilador();
void desligaCompilador();

void insereSimbolo(simbolo *simb);
simbolo *buscaSimbolo(char *simb);
void removeSimbolo(int quant);
