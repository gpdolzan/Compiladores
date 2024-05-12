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
    instruction_count = 0;
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
        mepa_stream << "\t" << comando << " " << arg2 << ", " << arg1
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

tipo_variavel aplicarOperacao(const std::string &op,
                              tipo_variavel necessary_type, tipo_variavel var1,
                              tipo_variavel var2) {
  if (!((var1 == var2) && (var1 == t_int)))
    error("type mismatch");

  geraCodigo(op);

  return necessary_type;
}

void insereSimbolo(Simbolo *simb) { tabela_simb->push(simb); }

Simbolo *buscaSimbolo(const std::string &simb) {
  Simbolo *sim = tabela_simb->busca_simbolo(simb);

  if (sim == nullptr)
    error("Variável não declarada: " + simbolo_flex);

  return sim;
}

void removeSimbolos(int quant) {
  for (int i = 0; i < quant; i++) {
    delete tabela_simb->pop();
  }
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

void insereRotulo(Rotulo *rotulo) { tabela_rotulos->push(rotulo); }

void removeRotulos(int quantidade) {
  for (int i = 0; i < quantidade; i++)
    delete tabela_rotulos->pop();
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