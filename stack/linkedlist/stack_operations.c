#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}

int isFull(struct Node *top)
{
    // if we are unable to allocate memory in the RAM
    // it means our heap memory is full
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (p == NULL)
        return 1;
    return 0;
}

struct Node *push(struct Node *top, int x)
{
}

int main()
{
    struct Node *top = NULL;
    push(top, 78);
    return 0;
}