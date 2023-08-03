#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *ptr)
{
    if (ptr->top >= ptr->size)
        return 1;
    return 0;
}

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int push(struct Stack *ptr, int val)
{
    if (isFull(ptr)){
        printf("Stack overflow, Unable to push %d into arr \n", val);
        return 0;
    }
    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack already Empty !!!");
        return 0;
    }
    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 3;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    printf("Stack has been created successfully\n");

    push(sp, 7);
    push(sp, 17);
    push(sp, 69);
    push(sp, 369);
    push(sp, 34);
    push(sp, 21);

    // printf("%d \n", pop(sp));

    printf("isEmpty: %d\n", isEmpty(sp));
    printf("isFull: %d\n", isFull(sp));

    return 0;
}