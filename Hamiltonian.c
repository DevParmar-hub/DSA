#include<stdio.h>
#include<conio.h>
int n=4;
int s=0;
int x[20];
int G[5][5] = {
    {0, 0, 0, 0, 0},
    {0,0, 1, 1, 1},
    {0,1, 0, 1, 0},
    {0,1, 1, 0, 1},
    {0,1, 0, 1, 0}
};

void next(int k){
    int j;
    while(1){
        x[k]=(x[k]+1)%(n+1);
        if(x[k]==0)
        return;
        if(G[x[k-1]][x[k]]!=0){

            for(j=1;j<k;j++){
                if(x[j]==x[k])
                break;
            }
            if(j==k){
                if(k<n || k==n && G[x[k]][x[1]]!=0){
                    return;
                }
            }
        }
        
    }
}

void hamilton(int k){
    int j;
    while(1){
        next(k);
        if(x[k]==0)
        return;
        if(k==n){
            s++;
            printf("{");
            for(j=1;j<=n;j++){
                printf("%d ",x[j]);
            }
            printf("}\n");
        }
        else
        hamilton(k+1);
    }
}

void main(){
    int i;
    for(i=1;i<5;i++){
        x[i]=0;
    }
    x[1]=2;
    hamilton(2);
    if(s==0){
        printf("NO SOLN\n");
    }

}