#include <stdio.h>
#include <conio.h>
int x[20];
int g[20][20];
int s=0;
int n=4;
int m=3;
void nextValue(int k){
    int j;
    while(1){
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0)
        return;
        for(j=0;j<n;j++){
            if(g[k][j]!=0 && x[k]==x[j])
            break;
        }
        if(j==n){
            return;
        }
    }
}

void mColour(int k){
    int j;
    while(1){
        nextValue(k);
        if(x[k]==0)
        return;
        if(k==n-1){
             s++;
            printf("{");
            for(j=0;j<n;j++){
                printf("%d ",x[j]);
            }
            printf("}\n");
        }
        else
        mColour(k+1);
        
    }
}

void main(){
int i,j;
int matrix[4][4] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}
};
for(i=0;i<n;i++){
    x[i]=0;
}

for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        g[i][j]=matrix[i][j];
    }
}

mColour(0);
if(s==0){
    printf("No Solutions\n");
}

}