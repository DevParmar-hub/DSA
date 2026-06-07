#include <stdio.h>
#include <conio.h>
#include <string.h>

int s=0;
void prefixTable(int m,int pi[],char P[]){
    int k=0;int q;
    pi[0]=0;
    for(q=1;q<m;q++){
        while(k>0 && P[k]!=P[q]){
            k=pi[k-1];
        }
        if(P[k]==P[q]){
            k++;
        }
        pi[q]=k;
    }
}

void kmp(char P[],char T[]){
    int pi[20];
    int m,n,i,k,q,j;
    m=strlen(P);
    n=strlen(T);
    prefixTable(m,pi,P);
    q=0;
    for(i=0;i<n;i++){
        while(q>0 && T[i]!=P[q]){
            q=pi[q-1];
        }
        if(T[i]==P[q]){
            q++;
        }
        if(q==m){
            printf("Solution found at %d",i-m+1);
            s=s+1;
            q=pi[q-1];
        }
    }


}

void main(){
    char P[] = "AABA";
    char T[] = "AABAACAADAABA";

    kmp(P, T);
      if(s==0)
    {
        printf("Pattern not found");
    }
}