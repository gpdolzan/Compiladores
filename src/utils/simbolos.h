#ifndef __SIMBOLOS_H__
#define __SIMBOLOS_H__

#define TAM_SIMBOLO 48

typedef enum {
  simb_program, simb_var, simb_begin, simb_end,
  simb_label, simb_type, simb_array, simb_procedure,
  simb_function, simb_goto, simb_if, simb_else,
  simb_then, simb_while, simb_do, simb_or,
  simb_div, simb_and, simb_not, simb_read,
  simb_write, simb_true, simb_false, simb_atribuicao,
  simb_ponto_e_virgula, simb_dois_pontos, simb_virgula, simb_ponto,
  simb_abre_parenteses, simb_fecha_parenteses, simb_abre_chave, simb_fecha_chave,
  simb_abre_colchete, simb_fecha_colchete, simb_igual, simb_diferente,
  simb_menor_que, simb_menor_ou_igual, simb_maior_ou_igual, simb_maior_que,
  simb_mais, simb_menos, simb_multi, simb_identificador,
  simb_numero
} flex_simbolos;

typedef enum {
  t_int, t_bool
} tipo_variavel;

typedef struct {
  char identificador[TAM_SIMBOLO];
  tipo_variavel tipo_v;
  int nivel_lexico;
  int deslocamento;
} simbolo;

#endif