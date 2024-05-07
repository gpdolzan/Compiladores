#include "tabela_simbolos.h"

t_stack *iniciar_tabela() {
  t_stack *nova_tabela = (t_stack *)malloc(sizeof(t_stack));
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

void push(t_stack *tabela, simbolo *simbolo) {
  if (tabela != NULL) {
    t_node *novo_nodo = criar_nodo(simbolo, tabela->top);

    if (novo_nodo != NULL) {
      tabela->top = novo_nodo;

      if (tabela->bottom == NULL) {
        tabela->bottom = novo_nodo;
      }
    }
  }
}

int is_stack_empty(t_stack *tabela) {
  return (tabela == NULL || tabela->top == NULL);
}

simbolo *pop(t_stack *tabela) {
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

// void print_stack(t_stack *tabela) {
//   if (is_stack_empty(tabela)) {
//     printf("Stack is empty.\n");
//     return;
//   }
//   printf("Stack contains:\n");
//   t_node *current = tabela->top;
//   while (current != NULL) {
//     printf("%d\n",
//            *(int *)current->data); // Assuming the data is of type int
//     current = current->next;
//   }
// }