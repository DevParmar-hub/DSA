#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[10];
int vertices;

struct Node* getNode(void) {
    return (struct Node*)malloc(sizeof(struct Node));
}

void createGraph() {
    int i, edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    for(i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(i = 0; i < edges; i++) {
        printf("Enter edge (u v) meaning u -> v: ");
        scanf("%d %d", &u, &v); 

        struct Node* newNode = getNode();
        newNode->vertex = v; 
    
        newNode->next = adjList[u]; 
        adjList[u] = newNode;

        //this is same as insertion at head
        /*
            newNode=>next = head;
            head = newNode;
        */
    }
}

void display() {
    int i;
    struct Node* temp;

    printf("\nAdjacency List (Directed Graph):\n");
    for(i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        temp = adjList[i];
        while(temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    createGraph();
    display();
    return 0;
}