#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int s;
int x[10];

int  place(int k,int i){
    int j;
    for(j=0;j<k;j++){
        if((x[j]==i) || abs(x[j]-i)==abs(j-k))
        return 0;
    }
    return 1;
}

void nQueens(int k, int n){
    int i,j;
    for(i=0;i<n;i++){
        if(place(k,i)){
            x[k]=i;
            if(k==n-1){
                s++;
                printf("{");
                for(j=0;j<n;j++){
                    printf("%d ",x[j]);
                }
                printf("}\n");
            }
            else
            nQueens(k+1,n);
        }
    }
}

void main(){
    int n=4;
    nQueens(0,n);
    if(s==0)
    printf("NO SOLUTIONS\n");
}
