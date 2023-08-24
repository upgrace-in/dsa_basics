#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int maximumELE(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

// *A
int countSort(int *A, int n)
{

    int i, j;

    // Find the max ele in Arr
    int max = maximumELE(A, n);

    // Creating an array
    int *count = (int *)malloc((max + 1) * sizeof(int));

    // Filling 0 in the arr
    for (i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // Putting 0 or 1 as per the elements availability
    for (i = 0; i < n; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0; // counter for count array
    j = 0; // counter for given array

    // Filtering out the count array and creating the final array
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    int A[] = {1, 2, 3, 0, 5, 2, 3};
    int n = 7;

    printArray(A, n);
    countSort(A, n);
    printArray(A, n);

    return 0;
}