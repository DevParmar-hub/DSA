#include <stdio.h>

void printArray(int *a, int n)
{
    int j;
    for (j = 0; j < n; j++)
    {
        printf("%d\t", a[j]);
    }
    printf("\n");
}

int partition(int a[], int low, int high)
{
    int pivot, i, j;
    pivot = a[low];
    i = low + 1;
    j = high;
    int temp;

    do
    {
        while (a[i] <= pivot)
        {
            i++;
        }
        while (a[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
    } while (i < j);

    temp = a[j];
    a[j] = a[low];
    a[low] = temp;
    return j;
}

void quickSort(int a[], int low, int high)
{
    int index;
    if (low < high)
    {
        index = partition(a, low, high);
        quickSort(a, low, index - 1);
        quickSort(a, index + 1, high);
    }
}

void main()
{
    int a[] = {3, 2, 7, 4, 3, 2};
    int n = 6;
    printArray(a, n);
    quickSort(a, 0, 5);
    printArray(a, n);
}