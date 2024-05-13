#include "utils/simbolos.hpp"
#include "utils/tabela_rotulos.hpp"
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
extern int nl, num_same_type_vars, num_total_vars, nivel_lexico, desloc, D[4],
    top_desloc, instruction_count;
extern std::stack<int> stack_block_var_count;

/* -------------------------------------------------------------------
 * prototipos globais
 * ------------------------------------------------------------------- */

void geraCodigo(const std::string &comando, const std::string &rot = "",
                const std::string &arg1 = "", const std::string &arg2 = "");
int yylex();
void yyerror(const std::string &s);

void iniciaCompilador();
void desligaCompilador();

void insereSimbolo(Simbolo *simb);
Simbolo *buscaSimbolo(const std::string &simb);
void removeSimbolos(int quant);
void colocaTipoEmSimbolos(tipo_variavel tipo, int quantidade);
void colocaTipoEmSimbolos(tipo_parametro_variavel tipo, int quantidade);

void insereRotulo(Rotulo *rotulo);
void removeRotulos(int quantidade);
Rotulo *buscaRotulo(const std::string &simb);

tipo_variavel aplicarOperacao(const std::string &op, tipo_variavel variavel,
                              tipo_variavel var1, tipo_variavel var2);
void start_while();
void do_while();
void end_while();

void start_if();
void end_if();
void start_else();
void end_else();

void visualizaTabela();
void error(const std::string &msg);