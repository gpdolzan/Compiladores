#include "utils/simbolos.hpp"
#include <fstream>
#include <stack>
#include <string>

/* -------------------------------------------------------------------
 * variáveis globais
 * ------------------------------------------------------------------- */

#define print

extern std::string simbolo_flex;
extern flex_simbolos relacao;
extern char token[TAM_SIMBOLO];
extern int nl, num_same_type_vars, num_total_vars, nivel_lexico, desloc, D[4], top_desloc;
extern std::stack<int> stack_block_var_count;

/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

void geraCodigo(const std::string& comando, const std::string& rot = "", int number = -1, int nivel_lexico = -1);
int yylex();
void yyerror(const std::string& s);

void iniciaCompilador();
void desligaCompilador();

void insereSimbolo(Simbolo *simb);
Simbolo *buscaSimbolo(const std::string& simb);
void removeSimbolo(int quant);
void colocaTipoEmSimbolos(const std::string& tipo, int quantidade);

tipo_variavel aplicarOperacao(const std::string& op, tipo_variavel variavel, tipo_variavel var1, tipo_variavel var2);
void visualizaTabela();

void error(const std::string& msg);