#include <stdio.h>
#include <conio.h>

floydWarshall(int graph[5][5]){
    int pi[5][5];int dist[5][5];
    int i,j,k;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if (graph[i][j]==0 && i!=j)
            {
                dist[i][j]=999;
            }
            else
            {
                dist[i][j]=graph[i][j];
            }
        }
    }
     for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(i==j){
                pi[i][j]=-1;
            }
            else if(graph[i][j]==0)
            {
                pi[i][j]=-1;
            }
            else
            pi[i][j]=i;
        }
    }
    for(k=0;k<5;k++){
        for(i=0;i<5;i++){
            for(j=0;j<5;j++){
                if(dist[i][k]!=999 && dist[k][j]!=999 && dist[i][k]+dist[k][j]<dist[i][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    pi[i][j]=pi[k][j];
                }
            }
        }
    }

    printf("Distance Martrix\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(dist[i][j]==999){
                printf("INF\t");
            }
            else
            printf("%d\t",dist[i][j]);
        }
        printf("\n");
    }

     printf("Pi Martrix\n");
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            if(pi[i][j]==-1){
                printf("NIL\t");
            }
            else
            printf("%d\t",pi[i][j]);
        }
        printf("\n");
    }
}
void main(){
    int start=1;
    int graph[5][5] = {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };
    floydWarshall(graph);
}
