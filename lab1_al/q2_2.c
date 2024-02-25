#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node *next;
} Node;

typedef struct Edge {
    int src, dest;
} Edge;

struct Graph {
    Node **head;
};

struct Graph *createGraph(Edge edges[], int n, int N, int * isundirected) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->head = (Node **)malloc(100 * sizeof(Node *));

    for (int i = 0; i < 100; i++) {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->dest = dest;
        newNode->next = graph->head[src];

        graph->head[src] = newNode;

        if(*isundirected){
        Node *newNode1 = (Node *)malloc(sizeof(Node));
        newNode1->dest = src;
        newNode1->next = graph->head[dest];
        graph->head[dest] = newNode1;
    }}

    return graph;
}
void printGraph(struct Graph *graph, int N) {
    for (int i = 0; i < 10; i++) {

   
        struct Node *ptr1 = graph->head[i];
        while (ptr1 != NULL) {
            printf("(%d -> %d)\t", i, ptr1->dest); //source->desr is my source
            ptr1 = ptr1->next;
        }
        printf("\n");
    }
}
int main() {
    int N, n, undirected;

    printf("Enter the number of vertices: ");
    scanf("%d", &N);

    printf("Enter the number of edges: ");
    scanf("%d", &n);
    printf("is the graph undirected(1 for Yes, 0 for No)");
    scanf("%d", &undirected);
    Edge edges[n];

    for (int i = 0; i < n; i++) {
        printf("Enter source for edge %d: ", i + 1);
        scanf("%d", &edges[i].src);
        printf("Enter destination for edge %d: ", i + 1);
        scanf("%d", &edges[i].dest);
    }

    struct Graph *graph = createGraph(edges, n, N, &undirected);
    printGraph(graph,N);




    return 0;
}
