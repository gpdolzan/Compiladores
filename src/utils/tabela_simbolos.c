#include "tabela_simbolos.h"

tabela_simbolos *iniciar_tabela() {
  tabela_simbolos *nova_tabela = (tabela_simbolos *)malloc(sizeof(tabela_simbolos));
  if (nova_tabela != NULL) {
    nova_tabela->top = NULL;
    nova_tabela->bottom = NULL;
  }

  return nova_tabela;
}

t_node *criar_nodo(simbolo *simbolo, t_node *prev) {
  t_node *new_node = (t_node *)malloc(sizeof(t_node));
  if (new_node != NULL) {
    new_node->simbolo = simbolo;

    new_node->prev = prev;
    new_node->next = NULL;

    if (prev != NULL)
      prev->next = new_node;
  }

  return new_node;
}

void push(tabela_simbolos *tabela, simbolo *simbolo) {
  if (tabela != NULL) {
    t_node *novo_nodo = criar_nodo(simbolo, tabela->top);

    if (novo_nodo != NULL) {
      if (tabela->top == NULL) { // Caso a tabela esteja inicialmente vazia
        tabela->bottom = novo_nodo; // O primeiro elemento é tanto o topo quanto o fundo
      }
      tabela->top = novo_nodo; // Atualiza o topo para o novo nodo
    }
  }
}

void coloca_tipo_em_simbolos(tabela_simbolos *tabela, tipo_variavel tipo, int quantidade) {
    if (tabela == NULL || tabela->top == NULL) {
        printf("A tabela esta vazia ou não inicializada.\n");
        return;
    }

    t_node *current = tabela->top;
    int count = 0;

    while (current != NULL && count < quantidade) {
        current->simbolo->tipo_v = tipo;
        current = current->prev;
        count++;
    }

    if (count < quantidade) {
        printf("Aviso: apenas %d símbolos foram modificados, pois a tabela contém menos símbolos que a quantidade especificada.\n", count);
    }
}

int is_stack_empty(tabela_simbolos *tabela) {
  return (tabela == NULL || tabela->top == NULL);
}

simbolo *busca_simbolo(tabela_simbolos *tabela, char* simb)
{
  if (is_stack_empty(tabela)) {
    return NULL;
  }

  int tam_simb = strlen(simb);

  t_node *current = tabela->top;
  while (current != NULL) {
    int tam_id = strlen(current->simbolo->identificador);

    if(tam_id == tam_simb)
    {
      if(strncmp(simb, current->simbolo->identificador, tam_simb) == 0)
        return current->simbolo;
    }

    current = current->prev; // Mude para 'prev' para ir do topo ao fundo
  }
  return NULL;
}

simbolo *pop(tabela_simbolos *tabela) {
  if (is_stack_empty(tabela)) {
    return NULL;
  }

  t_node *top_node = tabela->top;
  simbolo *simbolo = top_node->simbolo;
  
  tabela->top = top_node->prev;
  free(top_node);

  if (tabela->top == NULL) {
    tabela->bottom = NULL;
  }

  return simbolo;
}

// Function to print a symbol
void print_simbolo(simbolo *s) {
    if (s != NULL) {
        printf("Simbolo: %s, Tipo: %d, Nivel Lexico: %d, Deslocamento: %d\n",
               s->identificador, s->tipo_v, s->nivel_lexico, s->deslocamento);
    } else {
        printf("Simbolo NULL\n");
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
    printf("┌─────────────────────────────────────────────────────────────┐\n");
    printf("│                          Tabela de Símbolos                 │\n");
    printf("├─────────────┬──────────┬───────────────┬────────────────────┤\n");
    printf("│   Símbolo   │   Tipo   │ Nível Léxico  │    Deslocamento    │\n");
    printf("├─────────────┼──────────┼───────────────┼────────────────────┤\n");
    while (current != NULL) {
        printf("│ %-11s │ %-8s │ %-13d │ %-18d │\n",
               current->simbolo->identificador,
               current->simbolo->tipo_v == t_int ? "Int" : "Bool",
               current->simbolo->nivel_lexico,
               current->simbolo->deslocamento);
        current = current->prev; // Mude para 'prev' para ir do topo ao fundo
        if (current != NULL) {
            printf("├─────────────┼──────────┼───────────────┼────────────────────┤\n");
        }
    }
    printf("└─────────────┴──────────┴───────────────┴────────────────────┘\n");
}