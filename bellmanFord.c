#include <stdio.h>
#include <conio.h>
struct edge{
    int u,v,w;
};

void bellmanFord(int graph[5][5],int source){
int i,j,E,u,v;
int dist[5];

struct edge Edges[20];
E=0;
for(i=0;i<5;i++){
    for(j=0;j<5;j++){
        if(graph[i][j]!=0)
        {
            Edges[E].u=i;
            Edges[E].v=j;
            Edges[E].w=graph[i][j];
            E++;
        }
    }
}

for(i=0;i<5;i++){
    dist[i]=9999;
}
dist[source]=0;

for (i=0;i<4;i++){
    for(j=0;j<E;j++){
        u=Edges[j].u;
        v=Edges[j].v;
        if(dist[u] != 9999 && dist[v]>dist[u]+Edges[j].w){
            dist[v]=dist[u]+Edges[j].w;
        }
    }
}
 for(j=0;j<E;j++){
        u=Edges[j].u;
        v=Edges[j].v;
        if(dist[u] != 9999 && dist[v]>dist[u]+Edges[j].w){
           printf("Graph contains a negative weight cycle!\n");
            return;
        }
    }

printf("The distance of the source from the other vertices\n");
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
    bellmanFord(graph,start);
}
