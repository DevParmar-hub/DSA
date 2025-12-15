#include <stdio.h>

int fibSearch(int arr[], int n, int key) {
    int fib2 = 0;   // F(k-2)
    int fib1 = 1;   // F(k-1)
    int fib = fib1 + fib2; // F(k)

    // Find the smallest Fibonacci number >= n
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    int offset = -1;

    while (fib > 1) {
        int i = (offset + fib2 < n-1) ? offset + fib2 : n-1;

        if (arr[i] < key) {
            // Move right
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }
        else if (arr[i] > key) {
            // Move left
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else {
            return i;   // found
        }
    }

    // Check last element
    if (fib1!=0 && arr[offset + 1] == key)
        return offset + 1;

    return -1;
}

int main() {
    int arr[] = {1, 3, 4, 7, 9, 12, 16, 21};
    int n = sizeof(arr)/sizeof(arr[0]);

    int key = 12;
    int idx = fibSearch(arr, n, key);

    if (idx != -1)
        printf("Found at index %d\n", idx);
    else
        printf("Not found\n");

    return 0;
}
