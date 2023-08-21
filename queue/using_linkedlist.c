#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;

struct Node
{
    int data;
    struct Node *next;
};

void transversal(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d \n", p->data);
        p = p->next;
    }
}

void enqueue(int val)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        printf("Queue is Full !!!\n");
    }
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

int dequeue()
{
    if (f == NULL)
    {
        printf("Queue is Empty !!!\n");
        return -1;
    }
    else
    {
        struct Node *sp = f;
        int val = sp->data;
        f = f->next;
        free(sp);
        return val;
    }
}

int main()
{

    enqueue(7);
    enqueue(4);
    enqueue(3);
    enqueue(2);

    printf("Dequeue Element: %d\n", dequeue());
    printf("Dequeue Element: %d\n", dequeue());
    printf("Dequeue Element: %d\n", dequeue());
    printf("Dequeue Element: %d\n", dequeue());
    printf("Dequeue Element: %d\n", dequeue());

    return 0;
}