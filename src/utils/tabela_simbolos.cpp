#include "../../includes/utils/tabela_simbolos.hpp"
#include <iostream>

t_node *criar_nodo(Simbolo *simbolo, t_node *prev) {
  t_node *new_node = new t_node();
  if (new_node != nullptr) {
    new_node->simbolo = simbolo;

    new_node->prev = prev;
    new_node->next = nullptr;

    if (prev != nullptr)
      prev->next = new_node;
  }

  return new_node;
}

void TabelaSimbolos::push(Simbolo *simbolo) {
  t_node *novo_nodo = criar_nodo(simbolo, this->top);

  if (novo_nodo != nullptr) {
    if (this->top == nullptr) { // Caso a tabela esteja inicialmente vazia
      this->bottom =
          novo_nodo; // O primeiro elemento é tanto o topo quanto o fundo
    }
    this->top = novo_nodo; // Atualiza o topo para o novo nodo
  }
}

void TabelaSimbolos::coloca_tipo_em_simbolos(tipo_variavel tipo,
                                             int quantidade) {
  if (this->is_stack_empty()) {
    std::cerr << "A tabela esta vazia\n";
    return;
  }

  t_node *current = this->top;
  int count = 0;

  while (current != nullptr && count < quantidade) {
    current->simbolo->tipo_v = tipo;
    current = current->prev;
    count++;
  }

  if (count < quantidade) {
    printf("Aviso: apenas %d símbolos foram modificados, pois a tabela contém "
           "menos símbolos que a quantidade especificada.\n",
           count);
  }
}

void TabelaSimbolos::coloca_tipo_em_simbolos(tipo_parametro_variavel tipo, int quantidade){
    if (this->is_stack_empty()) {
    std::cerr << "A tabela esta vazia\n";
    return;
  }

  t_node *current = this->top;
  int count = 0;

  while (current != nullptr && count < quantidade) {
    current->simbolo->tipo_param_var = tipo;
    current = current->prev;
    count++;
  }

  if (count < quantidade) {
    printf("Aviso: apenas %d símbolos foram modificados, pois a tabela contém "
           "menos símbolos que a quantidade especificada.\n",
           count);
  }
}

int TabelaSimbolos::is_stack_empty() { return this->top == nullptr; }

Simbolo *TabelaSimbolos::busca_simbolo(const std::string &simb) {
  if (this->is_stack_empty()) {
    return nullptr;
  }

  t_node *current = this->top;
  while (current != nullptr) {
    if (current->simbolo->identificador == simb)
      return current->simbolo;

    current = current->prev; // Mude para 'prev' para ir do topo ao fundo
  }

  return nullptr;
}

Simbolo *TabelaSimbolos::pop() {
  if (this->is_stack_empty()) {
    return nullptr;
  }

  t_node *top_node = this->top;
  Simbolo *simbolo = top_node->simbolo;

  this->top = top_node->prev;
  free(top_node);

  if (this->top == nullptr) {
    this->bottom = nullptr;
  }

  return simbolo;
}

// Function to print a symbol
void print_simbolo(Simbolo *s) {
  if (s != nullptr) {
    printf("Simbolo: %s, Tipo: %d, Nivel Lexico: %d, Deslocamento: %d\n",
           s->identificador.c_str(), s->tipo_v, s->nivel_lexico,
           s->deslocamento);
  } else {
    printf("Simbolo nullptr\n");
  }
}

void TabelaSimbolos::print_tabela() {
  if (this->is_stack_empty()) {
    printf("┌─────────────────┐\n");
    printf("│  Tabela Vazia!  │\n");
    printf("└─────────────────┘\n");
    return;
  }

  t_node *current = this->top;
  printf("┌──────────────────────────────────────────────────────────────┐\n");
  printf("│                          Tabela de Símbolos                  │\n");
  printf("├─────────────┬───────────┬───────────────┬────────────────────┤\n");
  printf("│   Símbolo   │   Tipo    │ Nível Léxico  │    Deslocamento    │\n");
  printf("├─────────────┼───────────┼───────────────┼────────────────────┤\n");
  while (current != nullptr) {
    printf("│ %-11s │ %-9s │ %-13d │ %-18d │\n",
           current->simbolo->identificador.c_str(),
           current->simbolo->tipo_v == t_undefined
               ? "Undefined"
               : (current->simbolo->tipo_v == t_int ? "Inteiro" : "Booleano"),
           current->simbolo->nivel_lexico, current->simbolo->deslocamento);
    current = current->prev; // Mude para 'prev' para ir do topo ao fundo
    if (current != nullptr) {
      printf(
          "├─────────────┼───────────┼───────────────┼────────────────────┤\n");
    }
  }
  printf("└─────────────┴───────────┴───────────────┴────────────────────┘\n");
}