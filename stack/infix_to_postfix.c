#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int stackTop(struct Stack *ptr)
{
    return ptr->arr[ptr->top];
}

int precendence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return 1;
    return 0;
}

char *infixToPostfix(char *infix)
{
    // creating a stack for operators to be filled
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    // creating an empty postfix expression
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));

    int i = 0; // Track infix tranversal
    int j = 0; // Track postfix addition
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precendence(infix[i]) > precendence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }

    // adding the last left elements from the stack
    // to the end of the expression in postfix
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }

    // making the last element null
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "x-y/z-k*d";
    printf("Postfix is %s", infixToPostfix(infix));
    return 0;
}