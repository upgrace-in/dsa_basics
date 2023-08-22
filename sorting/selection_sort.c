#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int key, temp;
    for (int i = 0; i < n - 1; i++)
    {
        key = i;
        printf("Checking for %d \n", A[key]);
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[key])
            {
                key = j;
            }
            printf("J = %d while key = %d and A[j] = %d, A[key] = %d \n", j, key, A[j], A[key]);
        }
        temp = A[i];
        A[i] = A[key];
        A[key] = temp;
        printArray(A, n);
        printf("\n");
    }
}

int main()
{

    int A[] = {3, 45, 21, 5, 1, 23};
    int n = 6;

    printArray(A, n);
    selectionSort(A, n);
    // printArray(A, n);

    return 0;
}