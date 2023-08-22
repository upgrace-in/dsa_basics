#include <stdio.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int temp, isSorted = 0;
    for (int i = 0; i < n - 1; i++) // for number of passes
    {
        printf("PASS %d \n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++) // for checks
        {
            if (A[j] > A[j + 1])
            {
                /*Swapping*/
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted == 1)
        {
            break;
        }
    }
}

int main()
{

    // int A[] = {12, 54, 65, 7, 23, 9};
    int A[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    printArray(A, n);
    bubbleSort(A, n);
    printArray(A, n);
    return 0;
}