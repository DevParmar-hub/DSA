#include <stdio.h>
#include <conio.h>

void binarySearch(int arr[],int low, int high,int target){
    while(low<=high){
    int mid= low+(high-low)/2;
    if(arr[mid]==target)
    {
        printf("Targer found at %d th location",mid);
        return;
    }
    else if( arr[mid]>target)
    high=mid-1;
    else
    low=mid+1;
    }
}

void main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int n=8;
    int low=0;
    int high=8;
    int target=3;
    binarySearch(arr,low,high,target);
}