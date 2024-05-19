#include "../includes/compilador.hpp"
#include "../includes/utils/simbolos.hpp"
#include "../includes/utils/tabela_rotulos.hpp"
#include "../includes/utils/tabela_simbolos.hpp"

#include <iostream>
#include <string>

std::string simbolo_flex;
flex_simbolos relacao;
char token[TAM_SIMBOLO];
TabelaSimbolos *tabela_simb;
TabelaRotulos *tabela_rotulos;

std::ofstream mepa_stream;
std::string meu_token;
int nl = 1, num_same_type_vars = 0, num_total_vars = 0, top_desloc = 0,
    instruction_count = 0, bottom_desloc = 0;
int D[4] = {0, 0, 0, 0};

std::stack<int> stack_block_var_count;

void geraCodigo(const std::string &comando, const std::string &rot,
                const std::string &arg1, const std::string &arg2) {
  if (rot == "") {
    if (arg1 == "")
      mepa_stream << "\t" << comando << std::endl;
    else {
      if (arg2 == "")
        mepa_stream << "\t" << comando << " " << arg1 << std::endl;
      else
        mepa_stream << "\t" << comando << " " << arg1 << ", " << arg2
                    << std::endl;
    }
  } else {
    mepa_stream << rot << ": " << comando << std::endl;
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
  tabela_rotulos = new TabelaRotulos;
}

void desligaCompilador() {}

Param aplicarOperacao(const std::string &op, Param var1, Param var2) {
  tipo_variavel result_type;
  tipo_variavel needed_type;

  if (op == "CMME") {
    result_type = t_bool;
    needed_type = t_int;
  } else if (op == "CMMA") {
    result_type = t_bool;
    needed_type = t_int;
  } else if (op == "CMIG") {
    result_type = t_bool;
    needed_type = t_int;
  } else if (op == "CMDG") {
    result_type = t_bool;
    needed_type = t_int;
  } else if (op == "CMAG") {
    result_type = t_bool;
    needed_type = t_int;
  } else if (op == "CMEG") {
    result_type = t_bool;
    needed_type = t_int;
  } else if (op == "SOMA") {
    result_type = t_int;
    needed_type = t_int;
  } else if (op == "SUBT") {
    result_type = t_int;
    needed_type = t_int;
  } else if (op == "DISJ") {
    result_type = t_bool;
    needed_type = t_bool;
  } else if (op == "MULT") {
    result_type = t_int;
    needed_type = t_int;
  } else if (op == "DIVI") {
    result_type = t_int;
    needed_type = t_int;
  } else if (op == "CONJ") {
    result_type = t_bool;
    needed_type = t_bool;
  } else {
    error("Operação desconhecida");
  }

  if ((var1.tipo_v != var2.tipo_v) || (var1.tipo_v != needed_type))
    error("type mismatch");

  geraCodigo(op);

  tipo_parametro tipo_param = t_copy;
  if (var1.tipo_param == t_pointer || var2.tipo_param == t_pointer)
    tipo_param = t_pointer;

  return Param(result_type, tipo_param);
}

void insereSimbolo(Simbolo *simb) { tabela_simb->push(simb); }

Simbolo *buscaSimbolo(const std::string &simb) {
  Simbolo *sim = tabela_simb->buscaSimbolo(simb);

  if (sim == nullptr)
    error("Variável não declarada: " + simbolo_flex);

  return sim;
}

Simbolo *buscaSimbolo(int top_offset) {
  Simbolo *sim = tabela_simb->buscaSimbolo(top_offset);

  if (sim == nullptr)
    error("Variável não declarada: " + simbolo_flex);

  return sim;
}

void removeSimbolos(int quant) {
  for (int i = 0; i < quant; i++) {
    delete tabela_simb->pop();
  }
}

void colocaTipoEmSimbolos(tipo_variavel tipo, int quantidade) {
  tabela_simb->coloca_tipo_em_simbolos(tipo, quantidade);
}

void colocaTipoEmSimbolos(tipo_parametro_variavel tipo, int quantidade) {
  tabela_simb->coloca_tipo_em_simbolos(tipo, quantidade);
}

void colocaTipoEmSimbolos(tipo_parametro tipo, int quantidade){
  tabela_simb->coloca_tipo_em_simbolos(tipo, quantidade);
}

void insereRotulo(Rotulo *rotulo) { tabela_rotulos->push(rotulo); }

void removeRotulos(int quantidade) {
  for (int i = 0; i < quantidade; i++)
    tabela_rotulos->pop();
}

Rotulo *buscaRotulo(const std::string &simb) {
  return tabela_rotulos->busca_rotulo(simb);
}

Rotulo *buscaRotulo(int top_offset) {
  return tabela_rotulos->busca_rotulo(top_offset);
}

void visualizaTabela() { tabela_simb->print_tabela(); }

void start_while() {
  Rotulo *start_rot = new Rotulo();
  insereRotulo(start_rot);

  geraCodigo("NADA", start_rot->identificador);
  insereRotulo(new Rotulo());
}

void do_while() {
  Rotulo *end_rot = buscaRotulo(0);

  geraCodigo("DSVF", "", end_rot->identificador);
}

void end_while() {
  Rotulo *start_rot = buscaRotulo(1);
  Rotulo *end_rot = buscaRotulo(0);

  geraCodigo("DSVS", "", start_rot->identificador);
  geraCodigo("NADA", end_rot->identificador);

  removeRotulos(2);
}

void start_if() {
  Rotulo *end_if = new Rotulo();
  insereRotulo(end_if);

  geraCodigo("DSVF", "", end_if->identificador);
}

void end_if() {
  Rotulo *end_if = buscaRotulo(0);

  geraCodigo("NADA", end_if->identificador);

  removeRotulos(1);
}

void start_else() {
  Rotulo *start_else = buscaRotulo(0);

  Rotulo *end_if = new Rotulo();
  insereRotulo(end_if);

  geraCodigo("DSVS", "", end_if->identificador);
  geraCodigo("NADA", start_else->identificador);
}

void end_else() {
  Rotulo *end_if = buscaRotulo(0);

  geraCodigo("NADA", end_if->identificador);

  removeRotulos(2);
}

// espelho de bison::Parse::error
void error(const std::string &msg) {
  std::cerr << msg << " at line " << nl << '\n';
  exit(0);
}

void entraTopRotulo() {
  Rotulo *rot = buscaRotulo(0);
  if (rot == nullptr)
    error("Rotulo não encontrado em defineTopRotulo()");
  geraCodigo("ENPR", rot->identificador);
}

void desviaTopRotulo() {
  Rotulo *rot = buscaRotulo(0);
  geraCodigo("DSVS", "", rot->identificador);
}

void defineTopRotulo() {
  Rotulo *rot = buscaRotulo(0);
  if (rot == nullptr)
    error("Rotulo não encontrado em defineTopRotulo()");
  geraCodigo("NADA", rot->identificador);
}