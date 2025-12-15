#include<stdio.h>

int  getMax(int arr[],int n)
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
    }
    return max;
}
void countSort(int arr[],int n,int exp)
{
    int output [n];
    int count[10]={0};
for (int i=0;i<n;i++)
{
    int act;
    act=(arr[i]/exp)%10;
    count[act]++;
}
for(int i=1;i<10;i++)
{
count[i]+=count[i-1];
}
for(int i=n-1;i>=0;i--)
{
    int act=(arr[i]/exp)%10;
    output[count[act]-1]=arr[i];
    count[act]--;
}
for (int i = 0; i < n; i++)
        arr[i] = output[i];

}
void radixSort(int arr[],int n)
{
    int max=getMax(arr,n);
    for (int exp=1;max/exp>0;exp*=10)
    {
        countSort(arr,n,exp);
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d \t", arr[i]);
}
void main()
{
    int arr[]={12,45,23,97,34};
    int n=5;
    radixSort(arr,n);
    printArray(arr,n);
}