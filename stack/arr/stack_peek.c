#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    return 0;
}

int isFull(struct Stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

int push(struct Stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow, Unable to push %d into stack!!!\n", val);
        return 0;
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
        return 1;
    }
}

int pop(struct Stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack is empty !!!\n");
        return 0;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(struct Stack *ptr, int i)
{
    int arrIND = ptr->top - 1 + i;
    if (arrIND < 0 || arrIND > ptr->top)
    {
        printf("Not valid position for the stack\n");
        return 0;
    }
    else
    {
        return ptr->arr[arrIND];
    }
}

int main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 3;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));

    push(sp, 30);
    push(sp, 33);
    push(sp, 63);

    pop(sp);

    printf("Peek value of index %d is %d\n", 3, peek(sp, 3));

    printf("isFull: %d\n", isFull(sp));
    printf("isEmpty: %d\n", isEmpty(sp));

    return 0;
}