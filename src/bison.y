
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
std::list<Param> *params;
std::list<Param> *expression_list_types;
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

%type <Param> variavel_func
%type <Param> fator
%type <Param> expressao_simples
%type <Param> expressao
%type <Param> termo

%type <Simbolo*> variavel
%type <std::string> ident

%type <tipo_parametro> tipo_parametro
%type <tipo_variavel> tipo

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

      insereRotulo(new Rotulo());
   }
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   bloco_main PONTO 
   {
      geraCodigo("PARA");
      desligaCompilador();
   }
;

// 2. bloco -> parte_declara_vars comando_composto
bloco_main:
   parte_declara_vars 
   { 
      desviaTopRotulo(); 
   }
   parte_declara_subrotinas 
   { 
      defineTopRotulo(); 
   }
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

bloco:
   { 
      entraTopRotulo();
      top_desloc = 0;
      bottom_desloc = 0;
   }
   parte_declara_vars 
   { 
      desviaTopRotulo(); 
   }
   parte_declara_subrotinas 
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

      Simbolo* simb = buscaSimbolo(0);
      if (!simb->is_proc())
         error("Suposto ser um simbolo de procedimento ou funcao");

      geraCodigo("RTPR", "", std::to_string(simb->nivel_lexico), std::to_string(simb->parametros->size()));
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
   lista_var DOIS_PONTOS tipo PONTO_E_VIRGULA
   {
      colocaTipoEmSimbolos($3, num_same_type_vars);
      num_same_type_vars = 0;
   }
;

lista_var: 
   lista_var VIRGULA ident
   { 
      insereSimbolo(new Simbolo($3, lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
   | ident 
   { 
      insereSimbolo(new Simbolo($1, lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
;

ident: 
   IDENT
   {
      $$ = simbolo_flex;
   }
;

// 10. lista_idents -> lista_idents ',' IDENT | IDENT
lista_idents: 
   lista_idents VIRGULA ident
   /* {
      insereSimbolo(new Simbolo($3, lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   } */
   | ident
   /* {
      insereSimbolo(new Simbolo($1, lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   } */
;

/* Regra 11 - Parte de Declarações de Sub-Rotinas */
parte_declara_subrotinas:
    parte_declara_subrotinas declaracao_procedimento PONTO_E_VIRGULA 
    | parte_declara_subrotinas declaracao_funcao PONTO_E_VIRGULA 
    | %empty
;

/* Regra 12 - Declaração de Procedimento */
declaracao_procedimento:
   declaracao_procedimento_two
   bloco
   {
      removeRotulos(1);
      lexic_level--;
   }
;

declaracao_procedimento_two:
   PROCEDURE ident 
   {
      lexic_level++;
      num_total_vars = 0;
      
      Rotulo* rotulo = new Rotulo();
      insereRotulo(rotulo);
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo($2, lexic_level, params, rotulo);
      insereSimbolo(proce);

      int var_count = stack_block_var_count.top();
      stack_block_var_count.pop();
      stack_block_var_count.push(var_count + 1);
   }
   ABRE_PARENTESES parametros_formais
   {
      params = nullptr;
   }
   FECHA_PARENTESES PONTO_E_VIRGULA
;

/* Regra 13 - Declaração de Função */
declaracao_funcao:
    FUNCTION IDENT 
    parametros_formais 
    {
      num_vars = 0;
    }
    DOIS_PONTOS IDENT PONTO_E_VIRGULA
    bloco
    {
        // Configura ambiente de função no MEPA
    }
;

/* Regra 14 - Parâmetros Formais */
parametros_formais:
   parametros_formais PONTO_E_VIRGULA secao_parametros_formais_wrap
   | secao_parametros_formais_wrap
;

secao_parametros_formais_wrap: 
   {
      num_same_type_vars = 0;
   }
   secao_parametros_formais
;

/* Regra 15 - Secao Parâmetros Formais */
secao_parametros_formais:
   tipo_parametro lista_params DOIS_PONTOS tipo
   {
      for(int i = 0; i < num_same_type_vars; i++) {
         params->push_back(Param($4, $1));
      }

      colocaTipoEmSimbolos($4, num_same_type_vars);
      colocaTipoEmSimbolos($1, num_same_type_vars);

      num_same_type_vars = 0;
   }
;

lista_params: 
   lista_params VIRGULA ident
   {
      insereSimbolo(new Simbolo($3, lexic_level, -(4 + bottom_desloc), parametros_formais));
      bottom_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
   | ident
   {
      insereSimbolo(new Simbolo($1, lexic_level, -(4 + bottom_desloc), parametros_formais));
      bottom_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }
;

tipo_parametro:
   VAR
   {
      $$ = t_pointer;
   }
   | %empty
   {
      $$ = t_copy;
   }
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
   atribuicao
   | chamada_procedimento 
   | comando_composto
   | comando_repetitivo
   | comando_condicional
;

/* Regra 19 - Atribuicao */
atribuicao:
   variavel
   ATRIBUICAO
   expressao
   {
      if($1->tipo_v == $3.tipo_v)
         geraCodigo("ARMZ", "", std::to_string($1->nivel_lexico),  std::to_string($1->deslocamento));
      else
         error("Tipos incompatíveis na atribuição");
   }
;

/* Regra 20 - Chamada de Procedimento */
chamada_procedimento:
   variavel
   {
      if(!$1->is_proc())
         error("Chamada de procedimento inválida");
      if($1->parametros->size() != 0)
         error("Número de parâmetros inválido");
      geraCodigo("CHPR", "", $1->rotulo->identificador, std::to_string(lexic_level));
   }
   | variavel ABRE_PARENTESES 
   {
      expression_list_types = new std::list<Param>();
   }
   lista_de_expressoes FECHA_PARENTESES
   {
      Simbolo *proc = $1;
      if(!proc->is_proc())
         error("Chamada de procedimento inválida");
      if(proc->parametros->size() != expression_list_types->size())
         error("Número de parâmetros inválido");

      for (auto it = proc->parametros->begin(), it_list = expression_list_types->begin(); it != proc->parametros->end(); ++it, ++it_list) {
         if ((*it).tipo_v != (*it_list).tipo_v)
            error("Tipos de parâmetros incompatíveis");
      }
      delete expression_list_types;
      geraCodigo("CHPR", "", $1->rotulo->identificador, std::to_string(lexic_level));
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
   | %prec LOWER_THAN_ELSE %empty
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
      if($1.tipo_v != t_bool)
         error("Expressão booleana inválida");
   }
;

// 24. 
lista_de_expressoes:
   lista_de_expressoes VIRGULA expressao
   {
      expression_list_types->push_back($3);
   }
   | expressao
   {
      expression_list_types->push_back($1);
   }
;

// 25 & 26..
expressao: 
   expressao_simples MENOR_QUE expressao_simples 
   { 
      $$ = aplicarOperacao("CMME", $1, $3); 
   }
   | expressao_simples MAIOR_QUE expressao_simples 
   { 
      $$ = aplicarOperacao("CMMA", $1, $3);
   }
   | expressao_simples IGUAL expressao_simples 
   { 
      $$ = aplicarOperacao("CMIG", $1, $3);
   }
   | expressao_simples DIFERENTE expressao_simples 
   { 
      $$ = aplicarOperacao("CMDG", $1, $3);
   }
   | expressao_simples MAIOR_OU_IGUAL expressao_simples 
   { 
      $$ = aplicarOperacao("CMAG", $1, $3);
   }
   | expressao_simples MENOR_OU_IGUAL expressao_simples 
   { 
      $$ = aplicarOperacao("CMEG", $1, $3);
   }
   | expressao_simples
;

// 27.
expressao_simples:
   expressao_simples MAIS termo  
   { 
      $$ = aplicarOperacao("SOMA", $1, $3); 
   }
   | expressao_simples MENOS termo 
   { 
      $$ = aplicarOperacao("SUBT", $1, $3); 
   }
   | expressao_simples OR termo 
   { 
      $$ = aplicarOperacao("DISJ", $1, $3); 
   }
   | termo
;

// 28.
termo:
   termo MULTI fator 
   { 
      $$ = aplicarOperacao("MULT", $1, $3); 
   }
   | termo DIV fator 
   { 
      $$ = aplicarOperacao("DIVI", $1, $3); 
   }
   | termo AND fator 
   { 
      $$ = aplicarOperacao("CONJ", $1, $3); 
   } 
   | fator
;

// 29.
fator:
   NUMERO 
   {
      geraCodigo("CRCT", "", simbolo_flex);
      $$ = Param(t_int, t_copy);
   }
   | TRUE 
   {
      geraCodigo("CRCT", "", "1");
      $$ = Param(t_bool, t_copy);
   }
   | FALSE 
   {
      geraCodigo("CRCT", "", "0");
      $$ = Param(t_bool, t_copy);
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
      
      $$ = Param(simbolo->tipo_v, simbolo->tipo_param);
      geraCodigo("CRVL", "", std::to_string(simbolo->nivel_lexico), std::to_string(simbolo->deslocamento));
   }
;

tipo:
   IDENT
   {
      if (simbolo_flex == "boolean")
         $$ = t_bool;
      else if (simbolo_flex == "integer")
         $$ = t_int;
      else {
         $$ = t_undefined;
         error("Tipo inválido");
      }
   }
;

%%

void bison::Parser::error(const std::string& msg) {
    std::cerr << msg << " at line " << nl <<'\n';
    std::cerr << "with token " << simbolo_flex << '\n';
    exit(0);
}