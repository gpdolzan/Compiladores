#include "stack.h"

t_node* init_node(void* data)
{
    t_node *new_node = (t_node*)malloc(sizeof(t_node));
    if (new_node != NULL)
    {
        new_node->data = data;
        new_node->next = NULL;
    }
    return new_node;
}

void init_stack(t_stack *stk)
{
    if (stk != NULL)
    {
        stk->top = NULL;
    }
}

int is_stack_empty(t_stack *stk)
{
    return (stk == NULL || stk->top == NULL);
}

void push(t_stack *stk, void *data)
{
    if (stk != NULL)
    {
        t_node *new_node = init_node(data);
        if (new_node != NULL)
        {
            new_node->next = stk->top;
            stk->top = new_node;
        }
    }
}

void* pop(t_stack *stk)
{
    if (is_stack_empty(stk))
    {
        return NULL; // Stack is empty or not initialized
    }
    t_node *top_node = stk->top;
    void *data = top_node->data;
    stk->top = top_node->next;
    free(top_node);
    return data;
}

void print_stack(t_stack *stk)
{
    if (is_stack_empty(stk))
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contains:\n");
    t_node *current = stk->top;
    while (current != NULL)
    {
        printf("%d\n", *(int *)current->data); // Assuming the data is of type int
        current = current->next;
    }
}