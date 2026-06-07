#include <stdio.h>
#include <conio.h>
int s[5]={1,4,11,23,3};
int m=12;
int n=5;
int ans[5]={0,0,0,0,0};
void sos(int sum,int k,int total){
    ans[k] = 1;
    if(sum+s[k]==m){
        printf("{");
        for(int i=0;i<5;i++){
            if(ans[i]==1)
            printf("%d, ",s[i]);
        }
        printf("}\n");
    }
    else if(k+1<n && sum+s[k]+s[k+1]<=m){
        sos(sum+s[k],k+1,total-s[k]);
    }
    if((k+1<n) && (sum+total-s[k]>=m) &&(sum+s[k+1]<=m)){
        ans[k] = 0;
        sos(sum,k+1,total-s[k]);
    }
}

void main(){
    int total=0;
    int sum=0;
    for(int i=0;i<5;i++){
        total=total+s[i];
    }
    sos(sum,0,total);
}