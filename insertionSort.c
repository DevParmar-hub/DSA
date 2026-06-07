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

void insertionSort(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void main()
{
    int a[] = {3, 2, 7, 4, 3, 2};
    int n = 6;
    printArray(a, n);
    insertionSort(a, n);
    printArray(a, n);
}