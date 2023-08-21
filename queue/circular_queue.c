#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct circularQueue *q)
{
    
    if ((q->r + 1) % q->size == q->f)
        return 1;
    return 0;
}

int isEmpty(struct circularQueue *q)
{
    
    if (q->r == q->f)
        return 1;
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("circularQueue is full !!! \n");
    }
    else
    {
        printf("Enqueue element %d \n", val);
        printf("%d %d \n", (q->r + 1) % q->size, q->f);
        q->r = (q->r + 1) % q->size;
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("circularQueue is empty !!! \n");
    }
    else
    {
        q->f = (q->f + 1) % q->size;
        a = q->arr[q->f];
        printf("Dequeue element %d \n", a);
        printf("%d %d \n", q->r, q->f);
    }
    return a;
}

int main()
{
    struct circularQueue q;
    q.size = 4;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    // Enqueue
    enqueue(&q, 12);
    enqueue(&q, 15);
    enqueue(&q, 1);
    dequeue(&q);
    dequeue(&q);
    dequeue(&q);
    enqueue(&q, 0);
    enqueue(&q, 7);
    enqueue(&q, 8);
    enqueue(&q, 8);
    enqueue(&q, 8);

    printf("isEmpty: %d \n", isEmpty(&q));
    printf("isFull: %d \n", isFull(&q));

    return 0;
}