#include "../includes/compilador.hpp"
#include "../includes/utils/simbolos.hpp"
#include "../includes/utils/tabela_simbolos.hpp"

#include <iostream>
#include <string>

std::string simbolo_flex;
flex_simbolos relacao;
char token[TAM_SIMBOLO];
TabelaSimbolos *tabela_simb;

std::ofstream mepa_stream;
std::string meu_token;
int nl = 1, num_same_type_vars = 0, num_total_vars = 0, top_desloc = 0,
    instruction_count = 0;
int D[4] = {0, 0, 0, 0};
std::stack<int> stack_block_var_count;

void geraCodigo(const std::string &comando, const std::string &rot, int number,
                int nivel_lexico) {
  if (rot == "") {
    if (number == -1)
      mepa_stream << "\t" << comando << std::endl;
    else {
      if (nivel_lexico == -1)
        mepa_stream << "\t" << comando << " " << number << std::endl;
      else
        mepa_stream << "\t" << comando << " " << nivel_lexico << ", " << number
                    << std::endl;
    }
  } else {
    mepa_stream << rot << ": " << comando;
  }

  instruction_count++;

  mepa_stream.flush();
}

int imprimeErro(const std::string &erro) {
  // fprintf(stderr, "Erro na linha %d - %s\n", nl, erro);
  // exit(-1);
  return 1;
}

void iniciaCompilador() {
  mepa_stream.open("mepa.txt", std::ofstream::out);
  tabela_simb = new TabelaSimbolos;
}

void desligaCompilador() {}

void insereSimbolo(Simbolo *simb) { tabela_simb->push(simb); }

Simbolo *buscaSimbolo(const std::string &simb) {
  Simbolo *sim = tabela_simb->busca_simbolo(simb);

  if (sim == nullptr)
    error("Variável não declarada: " + simbolo_flex);

  return sim;
}

void removeSimbolo(int quant) {
  for (int i = 0; i < quant; i++) {
    delete tabela_simb->pop();
  }
}

tipo_variavel aplicarOperacao(const std::string &op,
                              tipo_variavel necessary_type, tipo_variavel var1,
                              tipo_variavel var2) {
  if (!((var1 == var2) && (var1 == t_int)))
    error("type mismatch");

  geraCodigo(op);

  return necessary_type;
}

void colocaTipoEmSimbolos(const std::string &tipo, int quantidade) {
  tipo_variavel tipo_v;

  if (tipo == "boolean")
    tipo_v = t_bool;
  else if (tipo == "integer")
    tipo_v = t_int;
  else
    tipo_v = t_undefined;

  tabela_simb->coloca_tipo_em_simbolos(tipo_v, quantidade);
}

void visualizaTabela() { tabela_simb->print_tabela(); }

// espelho de bison::Parse::error
void error(const std::string &msg) {
  std::cerr << msg << " at line " << nl << '\n';
  exit(0);
}