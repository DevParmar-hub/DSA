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

void selectionSort(int *a, int n)
{
    int index, temp;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[index] > a[j])
            {
                index = j;
            }
        }
        temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

void main()
{
    int a[] = {3, 2, 7, 4, 3, 2};
    int n = 6;
    printArray(a, n);
    selectionSort(a, n);
    printArray(a, n);
}