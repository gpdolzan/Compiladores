
%{
#include <iostream>
#include <string>
#include <cmath>
#include "flex.hpp"
#include "../includes/compilador.hpp"

#define flags(STR) std::cerr << "\033[1;31m" << STR << "\033[0m\n"
#define flag std::cerr << "\033[1;31mFLAG\033[0m\n"

int lexic_level = 0;
int num_total_vars = 0;
int num_total_params = 0;
int num_same_type_vars = 0;
int top_desloc = 0;

std::list<Param> *params;
std::stack<std::list<Param>> expression_list_types = {};
std::stack<std::stack<Param>> calling_proc_params = {};
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

%type <Simbolo*> bloco
%type <Simbolo*> variavel
%type <Simbolo*> chamada_sem_pametro
%type <Simbolo*> declaracao_procedimento
%type <Simbolo*> declaracao_funcao
%type <Simbolo*> chamada_procedimento_parametros
%type <Simbolo*> chamada_funcao_sem_parametros
%type <std::string> ident

%type <int> parte_declara_vars

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
   }
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   <Simbolo*>{
      simbolo_main = new Simbolo("main", lexic_level, new std::list<Param>(), main_process);

      $$ = simbolo_main;
   }
   bloco PONTO 
   {
      geraCodigo("PARA");
      desligaCompilador();
   }
;

bloco:
   <Simbolo*>{
      Simbolo* proce = $<Simbolo*>0;
      
      if (proce->is_proc_or_func()) {
         entraProce(proce);
      }else if (!proce->is_main()) {
         error("Suposto ser um simbolo de procedimento ou funcao, final do bloco de "
               "declaracoes de subrotinas");
      }

      top_desloc = 0;
      $<Simbolo*>$ = proce;
   }
   parte_declara_vars
   <Simbolo*>{
      $1->number_vars = $2;

      $$ = $1;
   }
   parte_declara_subrotinas_wrap
   {
      if ($1->is_func())
         $1->allow_return = true;
   }
   comando_composto
   {
      Simbolo* proce = $1;

      if(!proce->is_main())
         removeSimbolos(proce->parametros->size() + proce->number_vars);

      geraCodigo("DMEM", proce->number_vars);

      visualizaTabela();

      if (proce->is_proc_or_func())
         geraCodigo("RTPR", proce->nivel_lexico, proce->parametros->size());

      if (proce->is_func())
         $1->allow_return = false;
   }
;

// 8. Parte de Declaracoes de variaveis
parte_declara_vars: 
   VAR declara_vars 
   {
      geraCodigo("AMEM", num_total_vars);
      $$ = num_total_vars;
      visualizaTabela();
   }
   | %empty
   {
      $$ = 0;
   }
;
 
// 9. Declaração de variáveis
declara_vars:
   declara_vars declara_var
   | declara_var
;

declara_var:
   {
      num_same_type_vars = 0;
   }
   lista_var DOIS_PONTOS tipo PONTO_E_VIRGULA
   {
      colocaTipoEmSimbolos($<tipo_variavel>4, num_same_type_vars);
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
   }*/
   | ident
   /* {
      insereSimbolo(new Simbolo($1, lexic_level, top_desloc, variavel_simples));
      top_desloc++;
      num_total_vars++;
      num_same_type_vars++;
   }*/
;

/* Regra 11 - Parte de Declarações de Sub-Rotinas */
parte_declara_subrotinas_wrap:
   {
      Simbolo *proc = $<Simbolo*>0;

      geraCodigo("DSVS", "", proc->rotulo_begin()->identificador);
   }
   parte_declara_subrotinas
   {
      Simbolo *proc = $<Simbolo*>0;

      geraCodigo("NADA", proc->rotulo_begin()->identificador);
   }
   | %empty
;

parte_declara_subrotinas:
   parte_declara_subrotinas parte_declara_subrotinas_two
   | parte_declara_subrotinas_two 
;

parte_declara_subrotinas_two:
   declaracao_procedimento bloco PONTO_E_VIRGULA
   {
      lexic_level--;
   }
   | declaracao_funcao
   bloco PONTO_E_VIRGULA
   {
      lexic_level--;
   }
;

/* Regra 12 - Declaração de Procedimento */
declaracao_procedimento:
   PROCEDURE ident
   <Simbolo*>{
      lexic_level++;
      num_total_vars = 0;
      num_total_params = 0;
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo($2, lexic_level, params, process);
      insereSimbolo(proce);

      $$ = proce;
   }
   declaracao_params PONTO_E_VIRGULA
   {
      $$ = $3;
   }
;

/* Regra 13 - Declaração de Função */
declaracao_funcao:
   FUNCTION ident
   <Simbolo*>{
      lexic_level++;
      num_total_vars = 0;
      num_total_params = 0;
      
      params = new std::list<Param>();
      Simbolo *proce = new Simbolo($2, lexic_level, params, function);
      insereSimbolo(proce);
      
      $$ = proce;
   }
   declaracao_params DOIS_PONTOS tipo PONTO_E_VIRGULA
   {
      $$ = $3;
      $3->tipo_param = t_copy;
      $3->deslocamento = -(4 + num_total_params);
      $3->tipo_v = $6;
   }
;

declaracao_params:
   ABRE_PARENTESES parametros_formais
   {
      colocaDeslocEmParams(num_total_params);
      
      params = nullptr;
   }
   FECHA_PARENTESES
   | %empty
   {
      params = nullptr;
   }
;

/* Regra 14 - Parâmetros Formais */
parametros_formais:
   parametros_formais PONTO_E_VIRGULA secao_parametros_formais
   | secao_parametros_formais
;

/* Regra 15 - Secao Parâmetros Formais */
secao_parametros_formais:
   {
      num_same_type_vars = 0;
   }
   tipo_parametro lista_params DOIS_PONTOS tipo
   {
      tipo_variavel tipo_v = $<tipo_variavel>5;
      tipo_parametro tipo_param = $<tipo_parametro>2;

      for(int i = 0;i < num_same_type_vars;i++) {
         params->push_back(Param(tipo_v, tipo_param));
      }

      colocaTipoEmSimbolos(tipo_v, num_same_type_vars);
      colocaTipoEmSimbolos(tipo_param, num_same_type_vars);
   }
;

lista_params:
   lista_params VIRGULA ident 
   {
      insereSimbolo(new Simbolo($3, lexic_level, 0, parametros_formais));
      num_total_params++;
      num_same_type_vars++;
   }
   | ident
   {
      insereSimbolo(new Simbolo($1, lexic_level, 0, parametros_formais));
      num_total_params++;
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
   T_BEGIN lista_comandos T_END
;

lista_comandos:
   lista_comandos PONTO_E_VIRGULA comando
   | comando
;

/* Regra 17 - Comando */
comando:
   NUMERO DOIS_PONTOS comando_sem_rotulo
   | comando_sem_rotulo
   | %empty
;

/* Regra 18 - Comando sem Rotulo - FALTA READ E WRITE*/
comando_sem_rotulo:
   atribuicao
   | chamada_procedimento
   | comando_composto
   | comando_repetitivo
   | comando_condicional
   | WRITE ABRE_PARENTESES lista_write FECHA_PARENTESES
   | READ ABRE_PARENTESES lista_read FECHA_PARENTESES
;

lista_write:
   lista_write VIRGULA expressao
   {
      geraCodigo("IMPR");
   }
   | expressao
   {
      geraCodigo("IMPR");
   }
;

lista_read:
   lista_read VIRGULA variavel
   {
      geraCodigo("LEIT");
      aplicarArmazena($3);
   }
   | variavel
   {
      geraCodigo("LEIT");
      aplicarArmazena($1);
   }
;


/* Regra 19 - Atribuicao */
atribuicao:
   variavel
   ATRIBUICAO
   expressao
   {
      if($1->is_func())
         if(!$1->allow_return)
            error("Função não pode ser usada como variável");
      
      if($1->tipo_v == $3.tipo_v)
         aplicarArmazena($1);
      else
         error("Tipos incompatíveis na atribuição");
   }
;

/* Regra 20 - Chamada de Procedimento */
chamada_procedimento:
   chamada_sem_pametro
   {
      if(!$1->is_proc_or_func())
         error("Chamada de procedimento inválida");
      if($1->parametros->size() != 0)
         error("Número de parâmetros inválido");
      if($1->is_func())
         geraCodigo("AMEM", 1);
      geraCodigo("CHPR", "", $1->rotulo_enpr()->identificador, std::to_string(lexic_level));
      if($1->is_func())
         geraCodigo("DMEM", 1);
   }
   | chamada_procedimento_parametros
   {
      if($1->is_func())
         geraCodigo("DMEM", 1);
   }
;

chamada_sem_pametro:
   variavel
   {
      $$ = $1;
   }
   | variavel ABRE_PARENTESES FECHA_PARENTESES
   {
      $$ = $1;
   }
;

chamada_procedimento_parametros:
   variavel ABRE_PARENTESES 
   {
      Simbolo *proc = $1;

      if(!proc->is_proc_or_func())
         error("Chamada de procedimento inválida");
      
      expression_list_types.push({});
      calling_proc_params.push({});

      if(proc->is_func())
         geraCodigo("AMEM", 1);

      for(auto it = proc->parametros->rbegin();it != proc->parametros->rend();++it) {
         calling_proc_params.top().push(*it);
      }
   }
   lista_de_expressoes FECHA_PARENTESES
   {
      Simbolo *proc = $1;
      if(proc->parametros->size() != expression_list_types.top().size())
         error("Número de parâmetros inválido");

      for (auto it = proc->parametros->begin(), it_list = expression_list_types.top().begin();it != proc->parametros->end();++it, ++it_list) {
         if ((*it).tipo_v != (*it_list).tipo_v)
            error("Tipos de parâmetros incompatíveis");
      }

      geraCodigo("CHPR", "", $1->rotulo_enpr()->identificador, std::to_string(lexic_level));
      
      expression_list_types.pop();
      calling_proc_params.pop();

      $$ = $1;
   }
;

chamada_funcao_sem_parametros:
   variavel ABRE_PARENTESES FECHA_PARENTESES
   {
      Simbolo *proc = $1;

      if(!proc->is_func())
         error("Chamada de função inválida");
      
      geraCodigo("AMEM", 1);
      geraCodigo("CHPR", "", $1->rotulo_enpr()->identificador, std::to_string(lexic_level));
      
      $$ = $1;
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
      expression_list_types.top().push_back($3);
      if(calling_proc_params.top().empty())
         error("Número de parâmetros inválido");
      calling_proc_params.top().pop();
   }
   | expressao
   {
      expression_list_types.top().push_back($1);
      if(calling_proc_params.top().empty())
         error("Número de parâmetros inválido");
      calling_proc_params.top().pop();
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
      geraCodigo("CRCT", 1);
      $$ = Param(t_bool, t_copy);
   }
   | FALSE 
   {
      geraCodigo("CRCT", 0);
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
   variavel 
   {
      Simbolo* simbolo = $1;
      
      if(simbolo->is_proc_or_func())
         error("Variável não pode ser um procedimento");
      
      if(!calling_proc_params.empty()) {
         if(calling_proc_params.top().empty())
            error("Número de parâmetros inválido");
         
         Param param = calling_proc_params.top().top();

         aplicarCarrega(simbolo, param);
      } else {
         aplicarCarrega(simbolo);
      }
      
      $$ = Param(simbolo->tipo_v, simbolo->tipo_param);
   }
   | chamada_procedimento_parametros
   {
      Simbolo* proc = $1;
      if(!proc->is_func())
         error("Chamada de função inválida");

      $$ = Param(proc->tipo_v, proc->tipo_param);
   }
   | chamada_funcao_sem_parametros
   {
      Simbolo* proc = $1;
      if(!proc->is_func())
         error("Chamada de função inválida");

      $$ = Param(proc->tipo_v, proc->tipo_param);
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