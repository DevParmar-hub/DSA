#include <stdio.h>
#include <conio.h>
#include <string.h>

void printLCS(){

}

void lcs(char x[],char y[]){
    char answer[20];
    int i,j;
    int m=strlen(x);
    int n=strlen(y);
    int b[20][20];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 ||j==0){
                b[i][j]=0;
            }
            else if(x[i-1]==y[j-1]){
                b[i][j]=b[i-1][j-1]+1;
            }
            else{
                if(b[i-1][j]>=b[i][j-1]){
                    b[i][j]=b[i-1][j];
                }
                else{
                    b[i][j]=b[i][j-1];   
                }
            }
        }
    }

    printf("Length of LCS is %d\n",b[m][n]);

    int k=b[m][n];
    i=m;
    j=n;
    answer[k]='\0';
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            answer[k-1]=x[i-1];
            k--;
            i--;
            j--;
        }
        else if(b[i-1][j]>b[i][j-1]){
            i--;
        }
        else j--;
    }

    printf("The actual LCS is: %s\n", answer);
}


void main(){
    char x[]="AGGTAB";
    char y[]="GXTXAYB";
    lcs(x,y);
}