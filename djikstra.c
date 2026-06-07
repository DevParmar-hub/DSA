#include <stdio.h>
#include <conio.h>

void djikstra(int graph[5][5],int source){
int i,k,u,v;
int dist[5];
int check[5];

for(i=0;i<5;i++){
    check[i]=0;
    dist[i]=9999;
}

dist[source]=0;
for(k=0;k<5;k++){
int min=9999;
    for(i=0;i<5;i++){
        if(check[i]!=1 && dist[i]<min){
            min=dist[i];
            u=i;
        }
    }
    check[u]=1;
    for(v=0;v<5;v++){
        if(check[v]!=1 && graph[u][v]!=0){
            if(dist[v]>graph[u][v]+dist[u]){
                dist[v]=graph[u][v]+dist[u];
            }
        }
    }

}
 printf("Distance from the source to all other paths\n");
    for(i=0;i<5;i++){
        printf("%d-%d=%d\n",source,i,dist[i]);
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
    djikstra(graph,start);
}
