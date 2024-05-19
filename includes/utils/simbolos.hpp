#ifndef __SIMBOLOS_H__
#define __SIMBOLOS_H__

#include "tabela_rotulos.hpp"
#include <list>
#include <string>

#define TAM_SIMBOLO 48

typedef enum {
  simb_program,
  simb_var,
  simb_begin,
  simb_end,
  simb_label,
  simb_type,
  simb_array,
  simb_procedure,
  simb_function,
  simb_goto,
  simb_if,
  simb_else,
  simb_then,
  simb_while,
  simb_do,
  simb_or,
  simb_div,
  simb_and,
  simb_not,
  simb_read,
  simb_write,
  simb_true,
  simb_false,
  simb_atribuicao,
  simb_ponto_e_virgula,
  simb_dois_pontos,
  simb_virgula,
  simb_ponto,
  simb_abre_parenteses,
  simb_fecha_parenteses,
  simb_abre_chave,
  simb_fecha_chave,
  simb_abre_colchete,
  simb_fecha_colchete,
  simb_igual,
  simb_diferente,
  simb_menor_que,
  simb_menor_ou_igual,
  simb_maior_ou_igual,
  simb_maior_que,
  simb_mais,
  simb_menos,
  simb_multi,
  simb_identificador,
  simb_numero
} flex_simbolos;

typedef enum { t_int, t_bool, t_undefined } tipo_variavel;
typedef enum { variavel_simples, parametros_formais } tipo_parametro_variavel;
typedef enum { var, process, function } tipo_simbolo;
typedef enum { t_copy, t_pointer } tipo_parametro;

class Param {
public:
  Param() = default;
  Param(tipo_variavel tipo_v, tipo_parametro tipo_param)
      : tipo_v{tipo_v}, tipo_param{tipo_param} {}

  tipo_variavel tipo_v;
  tipo_parametro tipo_param;
};

class Simbolo {
public:
  Simbolo(const std::string &identificador, int nivel_lexico, int deslocamento,
          tipo_parametro_variavel tipo_param_var)
      : identificador{identificador}, tipo_simbo{var},
        tipo_param_var{tipo_param_var}, nivel_lexico{nivel_lexico},
        deslocamento{deslocamento} {}

  Simbolo(const std::string &identificador, int nivel_lexico,
          std::list<Param> *parametros, Rotulo *rotulo)
      : identificador{identificador}, tipo_simbo{process},
        nivel_lexico{nivel_lexico}, parametros{parametros}, rotulo{rotulo} {}

  ~Simbolo() {
    if (parametros != nullptr)
      delete parametros;

    // if (rotulo != nullptr)
    //   delete rotulo;
  }

  int is_proc();

  std::string identificador;
  tipo_variavel tipo_v;
  tipo_parametro_variavel tipo_param_var;
  tipo_parametro tipo_param;

  int nivel_lexico;
  int deslocamento;

  std::list<Param> *parametros = nullptr;
  tipo_simbolo tipo_simbo;
  Rotulo *rotulo = nullptr;
};

#endif