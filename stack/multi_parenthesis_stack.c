#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    char *arr;
    int size;
    int top;
};

int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int push(struct Stack *s, int val)
{
    if (isFull(s))
    {
        printf("Stack is full !!!");
        return 0;
    }
    s->top++;
    s->arr[s->top] = val;
    return 1;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is Empty !!!");
        return 0;
    }
    int val = s->arr[s->top];
    s->top--;
    return val;
}

int match(char a, char b)
{
    if (a == '{' && b == '}')
        return 1;
    else if (a == '(' && b == ')')
        return 1;
    else if (a == '[' && b == ']')
        return 1;
    return 0;
}

int parenthesisMatch(char *exp)
{
    // Create and initalise the stack
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i]))
            {
                return 0;
            }
        }
    }

    if (isEmpty(sp))
        return 1;
    return 0;
}

int main()
{
    char *exp = "{((8)*([9]))}";
    if (parenthesisMatch(exp))
    {
        printf("Matched !!!");
    }
    else
    {
        printf("Not Matched !!!");
    }
    return 0;
}