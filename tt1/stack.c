#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("Sorry bruv the Stacks empty\n");
        return 1;
    }
    else
    {
        printf("Push is available\n");
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        printf("Sorry bruv the Stacks full\n");
        return 1;
    }
    else
    {
        printf("Push available\n");
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        printf("Affirmative\n");
    }
    else
        printf("Sorry bruv The stack aint Empty\n");
}
int pop(struct stack *ptr)
{
    int var;
    if (isEmpty(ptr))
    {
        printf("Sorry bruv the Stack is Empty\n");
        return 0;
    }
    else
    {
        var = ptr->arr[ptr->top];
        ptr->top--;
        return var;
    }
}
void display(struct stack *ptr)
{
    int i;
    for (i = 0; i <= ptr->top; i++)
    {
        printf("%d\n", ptr->arr[i]);
    }
}
void main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    isEmpty(s);
    isFull(s);
    push(s, 10);
    push(s, 3);
    pop(s);
    push(s, 99);
    // printf("The popped element is %d",pop(s));
    display(s);
}
