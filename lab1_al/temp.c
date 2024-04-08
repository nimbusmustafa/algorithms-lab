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
    int *visited;
};

struct Graph *createGraph(Edge edges[], int n, int N, int * isundirected) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->head = (Node **)malloc(N * sizeof(Node *));
    graph->visited = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }
    for (int i = 0; i < N; i++) {
        graph->visited[i] = 0;
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

void bfs(struct Graph *graph, int startVertex){
    int queue[1000];
    int rear=-1;
    int front=-1;
    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("Visited %d \n", currentVertex);

        struct Node *temp = graph->head[currentVertex];
        while (temp != NULL) {
            int adjVertex = temp->dest;

            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                queue[++rear] = adjVertex;
            }

            temp = temp->next;
        }
    }

}
void printGraph(struct Graph *graph, int N) {
    for (int i = 0; i < N; i++) {

   
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
    bfs(graph,0);




    return 0;
}
