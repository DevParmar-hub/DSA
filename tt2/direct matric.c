#include<stdio.h>
#define MAX 10

int adj[MAX][MAX];
int vertices;

void createGraph() {
    int i, j, edges, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }
    printf("Enter no edges: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++) {
        printf("Enter edge (u,v): ");
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
}

void display() {
    int i, j;
    printf("\nAdjacency Matrix (Directed Graph):\n");
    for(i = 0; i < vertices; i++) {
        for(j = 0; j < vertices; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }
}

int main() {
    createGraph();
    display();
}