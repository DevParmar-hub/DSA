#include <stdio.h>
#include <conio.h>

void Prim(int graph[5][5], int start){
    int parent[5];
    int check[5];
    int dist[5];
    int min;
    int u,v;

    for(int i=0;i<5;i++){
        check[i]=0;
        dist[i]=9999;
    }
    parent[start]=-1;
    dist[start]=0;
    for(int k=0;k<5;k++){

        min=9999;
        for(int i=0;i<5;i++){
            if(check[i]!=1 && dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }
        check[u] = 1;
        for(v=0;v<5;v++){
            if(check[v]!=1 && graph[u][v]!=0 && graph[u][v]<dist[v]){
                dist[v]=graph[u][v];
                parent[v]=u;
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 0; i < 5; i++) {
        /* We skip the start node because it has no parent (-1) */
        if (i != start) {
            printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        }
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
    Prim(graph,start);
}