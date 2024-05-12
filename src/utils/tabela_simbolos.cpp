#include "../../includes/utils/tabela_simbolos.hpp"
#include <iostream>

tabela_simbolos *iniciar_tabela() {
  tabela_simbolos *nova_tabela = (tabela_simbolos *)malloc(sizeof(tabela_simbolos));
  if (nova_tabela != nullptr) {
    nova_tabela->top = nullptr;
    nova_tabela->bottom = nullptr;
  }

  return nova_tabela;
}

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

void push(tabela_simbolos *tabela, Simbolo *simbolo) {
  if (tabela != nullptr) {
    t_node *novo_nodo = criar_nodo(simbolo, tabela->top);

    if (novo_nodo != nullptr) {
      if (tabela->top == nullptr) { // Caso a tabela esteja inicialmente vazia
        tabela->bottom = novo_nodo; // O primeiro elemento é tanto o topo quanto o fundo
      }
      tabela->top = novo_nodo; // Atualiza o topo para o novo nodo
    }
  }
}

void coloca_tipo_em_simbolos(tabela_simbolos *tabela, tipo_variavel tipo, int quantidade) {
    if (tabela == nullptr || tabela->top == nullptr) {
        std::cout << "A tabela esta vazia ou não inicializada.\n";
        return;
    }

    t_node *current = tabela->top;
    int count = 0;

    while (current != nullptr && count < quantidade) {
        current->simbolo->tipo_v = tipo;
        current = current->prev;
        count++;
    }

    if (count < quantidade) {
        printf("Aviso: apenas %d símbolos foram modificados, pois a tabela contém menos símbolos que a quantidade especificada.\n", count);
    }
}

int is_stack_empty(tabela_simbolos *tabela) {
  return (tabela == nullptr || tabela->top == nullptr);
}

Simbolo *busca_simbolo(tabela_simbolos *tabela, std::string simb)
{
  if (is_stack_empty(tabela)) {
    return nullptr;
  }

  t_node *current = tabela->top;
  while (current != nullptr) {
    if(current->simbolo->identificador == simb)
      return current->simbolo;

    current = current->prev; // Mude para 'prev' para ir do topo ao fundo
  }
  return nullptr;
}

Simbolo *pop(tabela_simbolos *tabela) {
  if (is_stack_empty(tabela)) {
    return nullptr;
  }

  t_node *top_node = tabela->top;
  Simbolo *simbolo = top_node->simbolo;
  
  tabela->top = top_node->prev;
  free(top_node);

  if (tabela->top == nullptr) {
    tabela->bottom = nullptr;
  }

  return simbolo;
}

// Function to print a symbol
void print_simbolo(Simbolo *s) {
    if (s != nullptr) {
        printf("Simbolo: %s, Tipo: %d, Nivel Lexico: %d, Deslocamento: %d\n",
               s->identificador.c_str(), s->tipo_v, s->nivel_lexico, s->deslocamento);
    } else {
        printf("Simbolo nullptr\n");
    }
}

void print_tabela(tabela_simbolos *tabela) {
    if (is_stack_empty(tabela)) {
        printf("┌─────────────────┐\n");
        printf("│  Tabela Vazia!  │\n");
        printf("└─────────────────┘\n");
        return;
    }

    t_node *current = tabela->top;
    printf("┌──────────────────────────────────────────────────────────────┐\n");
    printf("│                          Tabela de Símbolos                  │\n");
    printf("├─────────────┬───────────┬───────────────┬────────────────────┤\n");
    printf("│   Símbolo   │   Tipo    │ Nível Léxico  │    Deslocamento    │\n");
    printf("├─────────────┼───────────┼───────────────┼────────────────────┤\n");
    while (current != nullptr) {
        printf("│ %-11s │ %-9s │ %-13d │ %-18d │\n",
               current->simbolo->identificador.c_str(),
               current->simbolo->tipo_v == t_undefined ? "Undefined" : (current->simbolo->tipo_v == t_int ? "Inteiro" : "Booleano"),
               current->simbolo->nivel_lexico,
               current->simbolo->deslocamento);
        current = current->prev; // Mude para 'prev' para ir do topo ao fundo
        if (current != nullptr) {
            printf("├─────────────┼───────────┼───────────────┼────────────────────┤\n");
        }
    }
    printf("└─────────────┴───────────┴───────────────┴────────────────────┘\n");
}