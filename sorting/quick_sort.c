#include <stdio.h>

/*Need to be understand*/

void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high, temp;

    do
    {

        while (A[i] <= pivot)
        {
            i++;
        }

        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int low, int high)
{
    int paritionIndex; // index of pivot after partition

    if (low < high)
    {
        paritionIndex = partition(A, low, high);
        quickSort(A, low, paritionIndex - 1);  // sort left subarray
        quickSort(A, paritionIndex + 1, high); // sort right subarray
    }
}

int main()
{
    int A[] = {3, 5, 2, 13, 12};
    int n = 5;
    printArray(A, n);
    quickSort(A, 0, n - 1);
    printArray(A, n);
    return 1;
}