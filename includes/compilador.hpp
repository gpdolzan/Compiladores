#include "utils/simbolos.hpp"
#include <string>
#include <fstream>

/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

#define print

extern std::string simbolo_flex;
extern flex_simbolos relacao;
extern char token[TAM_SIMBOLO];
extern int nivel_lexico;
extern int desloc;
extern int nl;

/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

void geraCodigo(std::string comando, std::string rot = "", int number = -1);
int yylex();
void yyerror(const char *s);

void iniciaCompilador();
void desligaCompilador();

void insereSimbolo(Simbolo *simb);
Simbolo *buscaSimbolo(char *simb);
void removeSimbolo(int quant);
void aplicarOperacao(char *op, tipo_variavel variavel);
void visualizaTabela();