%{
#include<stdio.h>
#include<string.h>

#include "compilador.h"
#include "compilador.tab.h"

//#define IMPRIME(STR) {};
#define IMPRIME(STR) printf("%s    # %s \n", STR, token);

int nl = 1;

%}

pulo_linha [\n]

descarte [\t ]+

ident [a-zA-Z][a-zA-Z0-9]*

numero [0-9]+

comentario "(*".*"*)"

%%

{pulo_linha} {nl++;}

{descarte}

{comentario}

program { simbolo_flex = simb_program;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("program");
          return PROGRAM;
 }

var      { simbolo_flex = simb_var;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("var");
          return VAR;
 }

begin { simbolo_flex = simb_begin;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("begin");
          return T_BEGIN;
 }

end { simbolo_flex = simb_end;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("end");
          return T_END;
 }

label  { simbolo_flex = simb_label;
          IMPRIME("label");
          return LABEL;
 }

type  { simbolo_flex = simb_type;
          IMPRIME("type");
          return TYPE;
 }

array  { simbolo_flex = simb_array;
          IMPRIME("array");
          return ARRAY;
 }

procedure  { simbolo_flex = simb_procedure;
          IMPRIME("procedure");
          return PROCEDURE;
 }

function  { simbolo_flex = simb_function;
          IMPRIME("function");
          return FUNCTION;
 }

goto  { simbolo_flex = simb_goto;
          IMPRIME("goto");
          return GOTO;
 }

if  { simbolo_flex = simb_if;
          IMPRIME("if");
          return IF;
 }

else  { simbolo_flex = simb_else;
          IMPRIME("else");
          return ELSE;
 }

then  { simbolo_flex = simb_then;
          IMPRIME("then");
          return THEN;
 }

while  { simbolo_flex = simb_while;
          IMPRIME("while");
          return WHILE;
 }

do  { simbolo_flex = simb_do;
          IMPRIME("do");
          return DO;
 }

or  { simbolo_flex = simb_or;
          IMPRIME("or");
          return OR;
 }

div  { simbolo_flex = simb_div;
          IMPRIME("div");
          return DIV;
 }

and  { simbolo_flex = simb_and;
          IMPRIME("and");
          return AND;
 }

not  { simbolo_flex = simb_not;
          IMPRIME("not");
          return NOT;
 }

read  { simbolo_flex = simb_read;
          IMPRIME("read");
          return READ;
 }

write  { simbolo_flex = simb_write;
          IMPRIME("write");
          return WRITE;
 }

true  { simbolo_flex = simb_true;
          IMPRIME("true");
          return TRUE;
 }

false  { simbolo_flex = simb_false;
          IMPRIME("false");
          return FALSE;
 }

:= { simbolo_flex = simb_atribuicao;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("atribuicao");
          return ATRIBUICAO;
 }

\; { simbolo_flex = simb_ponto_e_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("ponto_virgula");
          return PONTO_E_VIRGULA;
 }

\: { simbolo_flex = simb_dois_pontos;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("dois_pontos");
          return DOIS_PONTOS;
 }

\, { simbolo_flex = simb_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("virgula");
          return VIRGULA;
 }


\. { simbolo_flex = simb_ponto;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("ponto");
          return PONTO;
    }

\(  { simbolo_flex = simb_abre_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("abre_parenteses");
          return ABRE_PARENTESES;
    }

\)  { simbolo_flex = simb_fecha_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("fecha_parenteses");
          return FECHA_PARENTESES;
 }

\{  { simbolo_flex = simb_abre_chave;
          IMPRIME("abre_chave");
          return ABRE_CHAVE;
 }

\}  { simbolo_flex = simb_fecha_chave;
          IMPRIME("fecha_chave");
          return FECHA_CHAVE;
 }

\[ { simbolo_flex = simb_abre_colchete; 
          IMPRIME("abre_colchete");
          return ABRE_COLCHETE;
 }

\] { simbolo_flex = simb_fecha_colchete;
          IMPRIME("fech_colchete");
          return FECHA_COLCHETE;
 }

\=  { simbolo_flex = simb_igual;
          IMPRIME("igual");
          return IGUAL;
 }

\<>  { simbolo_flex = simb_diferente;
          IMPRIME("diferente");
          return DIFERENTE;
 }

\<  { simbolo_flex = simb_menor_que;
          IMPRIME("menor_que");
          return MENOR_QUE;
 }

\<=  { simbolo_flex = simb_menor_ou_igual;
          IMPRIME("menor_ou_igual");
          return MENOR_OU_IGUAL;
 }

\>=  { simbolo_flex = simb_maior_ou_igual;
          IMPRIME("maior_ou_igual");
          return MAIOR_OU_IGUAL;
 }

\>  { simbolo_flex = simb_maior_que;
          IMPRIME("maior_que");
          return MAIOR_QUE;
 }

\+  { simbolo_flex = simb_mais;
          IMPRIME("mais");
          return MAIS;
 }

\-  { simbolo_flex = simb_menos;
          IMPRIME("menos");
          return MENOS;
 }

\*  { simbolo_flex = simb_multi;
          IMPRIME("multiplica");
          return MULTI;
 }

{numero}  { simbolo_flex = simb_numero;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("numero");
          return NUMERO;
 }

{ident} { simbolo_flex = simb_identificador;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("ident");
          return IDENT;
        }

%%
