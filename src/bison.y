
%{
#include <iostream>
#include <string>
#include <cmath>
#include "flex.hpp"
#include "../includes/compilador.hpp"

#define flags(STR) std::cerr << "\033[1;31m" << STR << "\033[0m\n"
#define flag std::cerr << "\033[1;31mFLAG\033[0m\n"

int num_vars;
int lexic_level = 0;
%}

%require "3.7.4"
%language "C++"
%defines "bison.hpp"
%output "bison.cpp"

%define api.parser.class {Parser}
%define api.namespace {bison}
%define api.value.type variant
%param {yyscan_t scanner}

%code requires {
  #include "../includes/utils/simbolos.hpp"
}

%code provides
{
    #define YY_DECL \
        int yylex(bison::Parser::semantic_type *yylval, yyscan_t yyscanner)
    YY_DECL;
}

%type <tipo_variavel> variavel_func
%type <tipo_variavel> fator
%type <tipo_variavel> expressao_simples
%type <tipo_variavel> expressao
%type <tipo_variavel> termo
%type <Simbolo*> variavel

%token PROGRAM VAR T_BEGIN T_END
%token LABEL TYPE ARRAY PROCEDURE
%token FUNCTION GOTO IF ELSE
%token THEN WHILE DO OR
%token DIV AND NOT READ
%token WRITE TRUE FALSE ATRIBUICAO
%token PONTO_E_VIRGULA DOIS_PONTOS VIRGULA PONTO
%token ABRE_PARENTESES FECHA_PARENTESES ABRE_CHAVE FECHA_CHAVE
%token ABRE_COLCHETE FECHA_COLCHETE IGUAL DIFERENTE
%token MENOR_QUE MENOR_OU_IGUAL MAIOR_OU_IGUAL MAIOR_QUE
%token MAIS MENOS MULTI NUMERO
%token IDENT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

// 1. programa -> PROGRAM IDENT '(' lista_idents ')' ';' bloco '.'
programa:   
   {
      iniciaCompilador();
      geraCodigo("INPP");
   }
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   bloco PONTO 
   {
      geraCodigo("PARA");
      desligaCompilador();
   }
;

// 2. bloco -> parte_declara_vars comando_composto
bloco:
   parte_declara_vars
   comando_composto
   {
      if (!stack_block_var_count.empty()) {
         int var_count = stack_block_var_count.top();
         stack_block_var_count.pop();
         if (var_count > 0) {
            geraCodigo("DMEM", "", std::to_string(var_count));
            removeSimbolos(var_count);
            top_desloc -= var_count;
         }
      }
      visualizaTabela();
   }
;

// 8. Parte de Declaracoes de variaveis
parte_declara_vars:  
   { 
      num_vars = 0;
   } 
   VAR declara_vars 
   {
      geraCodigo("AMEM", "", std::to_string(num_total_vars));
      stack_block_var_count.push(num_total_vars);
      visualizaTabela();
   }
   | %empty
;
 
// 9. Declaração de variáveis
declara_vars: 
   declara_vars declara_var
   | declara_var
; 

declara_var:
   lista_id_var DOIS_PONTOS tipo PONTO_E_VIRGULA
;

tipo:
   IDENT
   {
      colocaTipoEmSimbolos(simbolo_flex,  num_same_type_vars);
      num_same_type_vars = 0;
   }
;

lista_id_var: 
   lista_id_var VIRGULA IDENT
   { 
      insereSimbolo(new Simbolo(simbolo_flex, lexic_level, top_desloc));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
   | IDENT 
   { 
      insereSimbolo(new Simbolo(simbolo_flex, lexic_level, top_desloc));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
;

// 10. lista_idents -> lista_idents ',' IDENT | IDENT
lista_idents: 
   lista_idents VIRGULA IDENT
   | IDENT
;

/* Regra 16 - Comando Composto */
comando_composto:
   {
      /* Imprimir o Debug */
   }
   T_BEGIN lista_comandos T_END
   {
      // Ação para iniciar bloco de comandos no MEPA
   }
;

lista_comandos:
   lista_comandos PONTO_E_VIRGULA comando
   | comando
   | %empty
;

/* Regra 17 - Comando */
comando:
   NUMERO DOIS_PONTOS comando_sem_rotulo
   | comando_sem_rotulo
   |%empty
;

/* Regra 18 - Comando sem Rotulo - FALTA READ E WRITE*/
comando_sem_rotulo:
    /* atribuicao_ou_chamada_proc |*/
   comando_composto
   | comando_repetitivo
   | comando_condicional
   | atribuicao
;

/* Regra 19 - Atribuicao */
atribuicao:
   variavel
   ATRIBUICAO
   expressao
   {
      if($1->tipo_v == $3)
         geraCodigo("ARMZ", "", std::to_string($1->deslocamento), std::to_string($1->nivel_lexico));
      else
         error("Tipos incompatíveis na atribuição\n");
   }
;

variavel:
   IDENT
   {
      Simbolo* simbolo = buscaSimbolo(simbolo_flex);
      $$ = simbolo;
   }
;

/* Regra 22 - Comando Condicional */
comando_condicional:
   if_then cond_else
;

if_then:
   IF expressao_booleana 
   {
      start_if();
   }
   THEN comando_sem_rotulo
;

cond_else:
   ELSE 
   {
      start_else();
   }
   comando_sem_rotulo
   {
      end_else();
   }
   | %prec LOWER_THAN_ELSE
   { 
      end_if();
   }
;

/* Regra 23 - Comando Repetitivo */
comando_repetitivo:
   WHILE
   {
      start_while();
   }
   expressao_booleana DO 
   {
      do_while();
   } 
   comando_sem_rotulo
   {
      end_while();
   }
;

expressao_booleana:
   expressao
   {
      if($1 != t_bool)
         error("Expressão booleana inválida\n");
   }
;

// 24. 
lista_de_expressoes:
   lista_de_expressoes VIRGULA expressao
   | expressao
;

// 25 & 26..
expressao: 
   expressao_simples MENOR_QUE expressao_simples 
   { 
      $$ = aplicarOperacao("CMME", t_bool, $1, $3); 
   }
   | expressao_simples MAIOR_QUE expressao_simples 
   { 
      $$ = aplicarOperacao("CMMA", t_bool, $1, $3);
   }
   | expressao_simples IGUAL expressao_simples 
   { 
      $$ = aplicarOperacao("CMIG", t_bool, $1, $3);
   }
   | expressao_simples DIFERENTE expressao_simples 
   { 
      $$ = aplicarOperacao("CMDG", t_bool, $1, $3);
   }
   | expressao_simples MAIOR_OU_IGUAL expressao_simples 
   { 
      $$ = aplicarOperacao("CMAG", t_bool, $1, $3);
   }
   | expressao_simples MENOR_OU_IGUAL expressao_simples 
   { 
      $$ = aplicarOperacao("CMEG", t_bool, $1, $3);
   }
   | expressao_simples  // ToDo aplicarOperacao
;

// 27.
expressao_simples: //ToDo aplicarOperacao
   expressao_simples MAIS termo  
   { 
      $$ = aplicarOperacao("SOMA", t_int, $1, $3); 
   }
   | expressao_simples MENOS termo 
   { 
      $$ = aplicarOperacao("SUBT", t_int, $1, $3); 
   }
   | expressao_simples OR termo 
   { 
      $$ = aplicarOperacao("DISJ", t_bool, $1, $3); 
   }
   | termo
;

// 28.
termo: //ToDo aplicarOperacao
   termo MULTI fator 
   { 
      $$ = aplicarOperacao("MULT", t_int, $1, $3); 
   }
   | termo DIV fator 
   { 
      $$ = aplicarOperacao("DIVI", t_int, $1, $3); 
   }
   | termo AND fator 
   { 
      $$ = aplicarOperacao("CONJ", t_bool, $1, $3); 
   } 
   | fator
;

// 29.
fator:
   NUMERO 
   {
      geraCodigo("CRCT", "", simbolo_flex);
      $$ = t_int;
   }
   | TRUE 
   {
      geraCodigo("CRCT", "", "1");
      $$ = t_bool;
   }
   | FALSE 
   {
      geraCodigo("CRCT", "", "0");
      $$ = t_bool;
   }
   | ABRE_PARENTESES expressao FECHA_PARENTESES
   {
      $$ = $2;
   }
   | variavel_func
;

// 30.
variavel_func:
   IDENT 
   {
      Simbolo* simbolo = buscaSimbolo(simbolo_flex);
      if (simbolo == nullptr) {
         std::cerr << "Variável não declarada: " << simbolo_flex << '\n';
         exit(0);
      }
      
      $$ = simbolo->tipo_v;

      geraCodigo("CRVL", "", std::to_string(simbolo->deslocamento), std::to_string(simbolo->nivel_lexico));
   }
;

%%

void bison::Parser::error(const std::string& msg) {
    std::cerr << msg << " at line " << nl <<'\n';
    std::cerr << "with token " << simbolo_flex << '\n';
    exit(0);
}