#include <stdio.h>
#include <conio.h>

struct edge
{
    int u, v, w;
};

int findParent(int parent[],int i){
    while(parent[i]!=-1){
        i=parent[i];
    }
    return i;
}

void unionSets(int parent[],int uRoot,int vRoot){
    int iRoot=findParent(parent,uRoot);
    int jRoot=findParent(parent,vRoot);
    parent[iRoot]=jRoot;
}
void Kruskal(int graph[5][5]){
struct edge Edge[20];
int parent[5];
int E=0;
int i,j,uRoot,vRoot;
struct edge temp;

for (i=0;i<5;i++){
    for(j=i+1;j<5;j++){
        if(graph[i][j]!=0){
            Edge[E].u=i;
            Edge[E].v=j;
            Edge[E].w=graph[i][j];
            E++;
        }
    }
}
for(i=0;i<5;i++){
    parent[i]=-1;
}

for(i=0;i<4;i++){
    for(j=0;j<4-i;j++){
        if(Edge[j+1].w>Edge[j].w){
            temp=Edge[j+1];
            Edge[j+1]=Edge[j];
            Edge[j]=temp;
        }
    }
}
printf("Edge \tWeight\n");

for(i=0;i<E;i++){
    uRoot=findParent(parent,Edge[i].u);
    vRoot=findParent(parent,Edge[i].v);

    if(uRoot!=vRoot){
        printf("%d - %d \t%d\n", Edge[i].u, Edge[i].v, Edge[i].w);
        unionSets(parent,uRoot,vRoot);
    }
}

}


void main()
{
    int start = 1;
    int graph[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}};
    Kruskal(graph);
}