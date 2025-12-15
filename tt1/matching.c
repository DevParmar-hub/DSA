#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
        return 1;
    else
        return 0;
}
void push(struct stack *ptr, char val)
{
    if (!isFull(ptr))
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
char pop(struct stack *ptr)
{
    char var;
    if (isEmpty(ptr))
    {
        printf("Emptyyyy!");
        return 0;
    }
    else
    {
        var = ptr->arr[ptr->top];
        ptr->top--;
        return var;
    }
}
int isBracket(char c)
{
    if (c == '(')
        return 1;
    else if (c == ')')
        return 2;
    else
        return 0;
}
void parenthesis_matching(char *eqn)
{
    int i = 0;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));
    while (eqn[i] != '\0')
    {
        if (isBracket(eqn[i]) == 1)
        {
            push(s, eqn[i]);
        }
        else if (isBracket(eqn[i]) == 2)
        {
            pop(s);
        }
        i++;
    }
    if (s->top == -1)
        printf("Brackets are all good mate");
    else
        printf("Your making a mistake brev");
}
void main()
{
    char eqn[] = "4+(5*(2+1)-3)";
    parenthesis_matching(eqn);
}