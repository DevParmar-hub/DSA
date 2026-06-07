// #include <stdio.h>

// void printArray(int *a, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         printf("%d\t", a[i]);
//     }
//     printf("\n");
// }

// int merge(int a[], int mid, int low, int high)
// {
//     int i, j, k, b[100];
//     i = low;
//     j = mid + 1;
//     k = low;
//     while (i <= mid && j <= high)
//     {
//         if (a[i] > a[j])
//         {
//             b[k] = a[j];
//             k++;
//             j++;
//         }
//         else
//         {
//             b[k] = a[i];
//             k++;
//             i++;
//         }
//     }
//     while (i <= mid)
//     {
//         b[k] = a[i];
//         k++;
//         i++;
//     }
//     while (j <= high)
//     {
//         b[k] = a[j];
//         k++;
//         j++;
//     }
//     for (int i = low; i <= high; i++)
//     {
//         a[i] = b[i];
//     }
// }

// void mergeSort(int *a, int low, int high)
// {
//     int mid;
//     if (low < high)
//     {
//         mid = (low + high) / 2;
//         mergeSort(a, low, mid);
//         mergeSort(a, mid + 1, high);
//         merge(a, mid, low, high);
//     }
// }

// void main()
// {
//     int a[] = {3, 2, 7, 4, 3, 2};
//     int n = 6;
//     printArray(a, n);
//     mergeSort(a, 0, 5);
//     printArray(a, n);
// }

#include <stdio.h>
#include<time.h>
#include<stdlib.h>


void printArray(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

int merge(int a[], int mid, int low, int high)
{

    int i, j, k, b[100000];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] > a[j])
        {
            b[k] = a[j];
            k++;
            j++;
        }
        else
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        a[i] = b[i];
    }
}

void mergeSort(int *a, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);
        merge(a, mid, low, high);
    }
}

void main()
{
    int n;
    clock_t t1=clock();
    printf("ENter the number of elements:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=rand()%100;
    }
    // printArray(arr, n);
    mergeSort(arr, 0, n-1);
    // printArray(arr, n);
    clock_t t2=clock();
    clock_t t3=t2-t1;
    printf("Time taken: %d \n", t3);
}