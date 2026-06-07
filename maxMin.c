#include <stdio.h>
#include <conio.h>

void maxMin(int arr[], int low, int high, int *max, int *min)
{
    int mid, max1, min1, max2, min2;
    if (low == high)
    {
        *max = arr[low];
        *min = arr[high];
        return;
    }
    else if (low == (high - 1))
    {
        if (arr[low] > arr[high])
        {
            *max = arr[low];
            *min = arr[high];
            return;
        }
        else
        {
            *max = arr[high];
            *min = arr[low];
            return;
        }
    }
    else
    {
        mid = low + (high - low) / 2;
        maxMin(arr, low, mid, &max1, &min1);
        maxMin(arr, mid + 1, high, &max2, &min2);

        *max = (max1 > max2) ? max1 : max2;
        *min = (min1 > min2) ? min2 : min1;
        return;
    }
}

void main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 8;
    int low = 0;
    int high = 8;
    int max, min;
    maxMin(arr, low, high, &max, &min);
    printf("Max is %d\n", max);
    printf("Min is %d", min);
    getch();
}