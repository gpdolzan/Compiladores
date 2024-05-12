#include "../includes/compilador.hpp"
#include "../includes/utils/simbolos.hpp"
#include "../includes/utils/tabela_simbolos.hpp"

#include <iostream>
#include <string>

std::string simbolo_flex;
flex_simbolos relacao;
char token[TAM_SIMBOLO];
tabela_simbolos *tabela_simb;

std::ofstream mepa_stream;
std::string meu_token;
int nl = 1, num_same_type_vars = 0, num_total_vars = 0, top_desloc = 0;
int D[4] = {0, 0, 0, 0};
std::stack<int> stack_block_var_count;

void geraCodigo(const std::string& comando, const std::string& rot, int number,
                int nivel_lexico) {
  if (rot == "") {
    if (number == -1)
      mepa_stream << "\t" << comando << std::endl;
    else {
      if (nivel_lexico == -1)
        mepa_stream << "\t" << comando << " " << number << std::endl;
      else
        mepa_stream << "\t" << comando << " " << nivel_lexico << ", " << number << std::endl;
    }
  } else {
    mepa_stream << rot << ": " << comando;
  }

  mepa_stream.flush();
}

int imprimeErro(const std::string& erro) {
  // fprintf(stderr, "Erro na linha %d - %s\n", nl, erro);
  // exit(-1);
  return 1;
}

void iniciaCompilador() {
  mepa_stream.open("mepa.txt", std::ofstream::out);
  tabela_simb = iniciar_tabela();
}

void desligaCompilador() {}

void insereSimbolo(Simbolo *simb) { push(tabela_simb, simb); }

Simbolo *buscaSimbolo(const std::string& simb) {
  t_node *current = tabela_simb->top;

  while (current != NULL) {
    if (current->simbolo->identificador == simb) {
      return current->simbolo;
    }
    current = current->prev;
  }

  error("Variável não declarada: " + simbolo_flex);

  return nullptr;
}

void removeSimbolo(int quant) {
  for (int i = 0; i < quant; i++) {
    pop(tabela_simb);
  }
}

tipo_variavel aplicarOperacao(const std::string& op, tipo_variavel necessary_type, tipo_variavel var1, tipo_variavel var2) {
  if (!((var1 == var2) && (var1 == t_int)))
      error("type mismatch");
  
  geraCodigo(op);

  return necessary_type;
}

void colocaTipoEmSimbolos(const std::string& tipo, int quantidade) {
  tipo_variavel tipo_v;

  if (tipo == "boolean")
    tipo_v = t_bool;
  else if (tipo == "integer")
    tipo_v = t_int;
  else
    tipo_v = t_undefined;

  coloca_tipo_em_simbolos(tabela_simb, tipo_v, quantidade);
}

void visualizaTabela() { print_tabela(tabela_simb); }

// espelho de bison::Parse::error
void error(const std::string& msg) {
    std::cerr << msg << " at line " << nl << '\n';
    exit(0);
}