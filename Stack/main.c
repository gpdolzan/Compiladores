#include "stack.h"

int main(int argc, char const *argv[])
{
    /* Programa Teste da Pilha */
    t_stack stk;
    init_stack(&stk);

    int values[] = {10, 20, 30, 40, 50};

    // Push values onto the stack
    for (int i = 0; i < 5; i++)
    {
        push(&stk, &values[i]);
        print_stack(&stk);
    }

    // Pop all values from the stack
    while (!is_stack_empty(&stk))
    {
        int *val = (int *)pop(&stk);
        printf("Popped: %d\n", *val);
        print_stack(&stk);
    }
    return 0;
}
