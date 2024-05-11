#include "../src/utils/tabela_simbolos.h"
#include <stdio.h>
#include <string.h>

// Function to create a symbol
simbolo *criar_simbolo(const char *nome, tipo_variavel tipo, int nivel, int desloc) {
    simbolo *s = (simbolo *)malloc(sizeof(simbolo));
    if (s != NULL) {
        strncpy(s->identificador, nome, TAM_SIMBOLO);
        s->tipo_v = tipo;
        s->nivel_lexico = nivel;
        s->deslocamento = desloc;
    }
    return s;
}

int main()
{
    tabela_simbolos *tabela = iniciar_tabela();

    // Checar se a tabela esta vazia
    printf("Tabela esta vazia? %s\n", is_stack_empty(tabela) ? "Sim" : "Nao");
    
    // Criar simbolos de teste
    simbolo *simbolos[] = {
        criar_simbolo("x", t_int, 1, 0),
        criar_simbolo("y", t_bool, 1, 4),
        criar_simbolo("z", t_int, 1, 8),
        criar_simbolo("function", t_int, 2, 12),
        criar_simbolo("flag", t_bool, 2, 16)
    };
    int num_simbolos = sizeof(simbolos) / sizeof(simbolos[0]);
    simbolo *simbolo_encontrado = NULL;

    // Imprimir tabela completa
    printf("Colocando elementos na tabela:\n");
    for (int i = 0; i < num_simbolos; i++) {
        printf("Adicionando...\n");
        print_simbolo(simbolos[i]);
        push(tabela, simbolos[i]);
        print_tabela(tabela);
    }

    // Imprimir tabela completa
    printf("Tabela depois de estar preenchida:\n");
    print_tabela(tabela);

    // Testar Busca
    printf("Buscando por simbolo y:\n");
    simbolo_encontrado = busca_simbolo(tabela, "y");
    print_simbolo(simbolo_encontrado);
    printf("Buscando por simbolo Rodrigo:\n");
    simbolo_encontrado = busca_simbolo(tabela, "Rodrigo");
    print_simbolo(simbolo_encontrado);

    printf("\n");

    printf("Modificando todos os simbolos para Int:\n");
    coloca_tipo_em_simbolos(tabela, t_int, 5);
    print_tabela(tabela);

    printf("\n");
    printf("Modificando todos os simbolos para Bool:\n");
    coloca_tipo_em_simbolos(tabela, t_bool, 5);
    print_tabela(tabela);

    // Remove 1 por 1
    printf("Removendo elementos um a um:\n");
    while (!is_stack_empty(tabela)) {
        simbolo *popped = pop(tabela);
        printf("Removido: %s\n", popped->identificador);
        free(popped);
        print_tabela(tabela);
    }

    printf("Tabela depois de remover tudo:\n");
    print_tabela(tabela);

    printf("Remover da tabela depois de estar vazia:\n");
    simbolo_encontrado = pop(tabela);
    print_simbolo(simbolo_encontrado);

    // Checar se a tabela esta vazia
    printf("Tabela esta vazia? %s\n", is_stack_empty(tabela) ? "Sim" : "Nao");

    // Free the table structure
    free(tabela);

    return 0;
}