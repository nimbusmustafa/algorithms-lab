#include <stdio.h>
#include <stdlib.h>

#define N 6
int n;

struct Node {
    int dest;
    struct Node *next;
};

struct Edge {
    int src, dest;
};

struct Graph {
    struct Node *head[N];
};

struct Graph *createGraph(struct Edge edges[], int n) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    for (int i = 0; i < N; i++) {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;

        newNode->next = graph->head[src];

        graph->head[src] = newNode;
    }

    return graph;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < N; i++) {
        struct Node *ptr = graph->head[i];
        while (ptr != NULL) {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

int main() {
    printf("Enter the number of edges: ");
    scanf("%d", &n);

    struct Edge edges[n];
    for (int i = 0; i < n; i++) {
        printf("Enter source for edge %d: ", i + 1);
        scanf("%d", &edges[i].src);
        printf("Enter destination for edge %d: ", i + 1);
        scanf("%d", &edges[i].dest);
    }

    struct Graph *graph = createGraph(edges, n);

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    return 0;
}
