
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars;

%}

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

%%

// 1. programa -> PROGRAM IDENT '(' lista_idents ')' ';' bloco '.'
programa:   
   {
      iniciaCompilador();
      geraCodigo (NULL, "INPP");
   }
   PROGRAM IDENT
   ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
   bloco PONTO 
   {
      geraCodigo (NULL, "PARA");
      desligaCompilador();
   }
;

// 2. bloco -> parte_declara_vars comando_composto
bloco:
   parte_declara_vars
   {
   }
   comando_composto
;

parte_declara_vars:  
   var
;

var: 
   { 
      num_vars = 0;
   } 
   VAR declara_vars
   |
;

declara_vars: 
   declara_vars declara_var
   | declara_var
;

declara_var : { }
   lista_id_var DOIS_PONTOS
   tipo
   {
      // vou ter o tipo e todos os identificadores

      geraCodigo(NULL, "AMEM", num_vars);
   }
   PONTO_E_VIRGULA
;

tipo: 
   IDENT
   {
      tipo_variavel tipo;
      if (strcmp(token, "integer") == 0) {
         tipo = t_int;
      } else if (strcmp(token, "boolean") == 0) {
         tipo = t_bool;
      }
      
      // ToDo
      pilhaSimbolos *fim = tabelaSimbolo->prev;
      for (int i = 0; i < num_vars; i++) {
         fim->tipov = tipo;
         fim = fim->prev;
      }
   }
;

lista_id_var: 
   lista_id_var VIRGULA IDENT
   { 
      num_vars++;

      //ToDo
      insereSimbolo
   }
   | IDENT 
   { 
      num_vars++;

      //ToDo
      insereSimbolo
   }
;

// 10. lista_idents -> lista_idents ',' IDENT | IDENT
lista_idents: 
   lista_idents VIRGULA IDENT
   | IDENT
;

comando_composto: 
   T_BEGIN comandos T_END
;

comandos:
;

// 24. 
lista_de_expressoes:
   lista_de_expressoes VIRGULA expressao
   | expressao
;

// 25 & 26..
expressao: 
   expressao_simples  // ToDo aplicarOperacao
   | expressao_simples MENOR_QUE expressao_simples { aplicarOperacao("CMME", BOOLEANO); }
   | expressao_simples MAIOR_QUE expressao_simples { aplicarOperacao("CMMA", BOOLEANO); }
   | expressao_simples IGUAL expressao_simples { aplicarOperacao("CMIG", BOOLEANO); }
   | expressao_simples DIFERENTE expressao_simples { aplicarOperacao("CMDG", BOOLEANO); }
   | expressao_simples MAIOR_OU_IGUAL expressao_simples { aplicarOperacao("CMAG", BOOLEANO); }
   | expressao_simples MENOR_OU_IGUAL expressao_simples { aplicarOperacao("CMEG", BOOLEANO); }
   expressao_simples  
;

// 27.
expressao_simples: //ToDo aplicarOperacao
   expressao_simples MAIS termo  { aplicarOperacao("SOMA", INTEIRO); }
   | expressao_simples MENOS termo { aplicarOperacao("SUBT", INTEIRO); }
   | expressao_simples OR termo { aplicarOperacao("DISJ", BOOLEANO); }
   | termo
;

// 28.
termo: //ToDo aplicarOperacao
   termo MULTI fator { aplicarOperacao("MULT", INTEIRO); }
   | termo DIV fator { aplicarOperacao("DIVI", INTEIRO); }
   | termo AND fator { aplicarOperacao("CONJ", BOOLEANO); }
   fator
;

// 29.
fator:
   variavel_func //ToDo carregar constantes
   | NUMERO {}
   | TRUE {}
   | FALSE {}
   | ABRE_PARENTESES expressao FECHA_PARENTESES
;

// 30.
variavel_func:
   IDENT
;

%%

int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de Simbolos
 * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();

   return 0;
}
