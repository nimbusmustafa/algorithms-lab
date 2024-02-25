#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node *next;
};

struct Edge {
    int src, dest;
};

struct Graph {
    struct Node *head;
};

struct Graph *createGraph(struct Edge edges[], int n, int numVertices) {
    struct Graph *graph = (struct Graph *)malloc(numVertices * sizeof(struct Graph));

    for (int i = 0; i < numVertices; i++) {
        graph[i].head = NULL;
    }

    for (int i = 0; i < n; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph[src].head;
        graph[src].head = newNode;
    }

    return graph;
}

void printGraph(struct Graph *graph, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        struct Node *ptr = graph[i].head;
        while (ptr != NULL) {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

void topologicalSort(struct Graph *graph, int numVertices) {
    int *inDegree = (int *)malloc(numVertices * sizeof(int));

    // Initialize in-degrees to 0
    for (int i = 0; i < numVertices; i++)
        inDegree[i] = 0;

    // Calculate in-degrees for each vertex
    for (int i = 0; i < numVertices; i++) {
        struct Node *ptr = graph[i].head;
        while (ptr != NULL) {
            inDegree[ptr->dest]++;
            ptr = ptr->next;
        }
    }

    // Create a queue to store nodes with in-degree 0
    int *queue = (int *)malloc(numVertices * sizeof(int));
    int front = 0, rear = 0;

    // Enqueue nodes with in-degree 0
    for (int i = 0; i < numVertices; i++) {
        if (inDegree[i] == 0)
            queue[rear++] = i;
    }

    // Perform source removal using a queue
    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        struct Node *ptr = graph[current].head;
        while (ptr != NULL) {
            // Decrement the in-degree of the adjacent vertices
            inDegree[ptr->dest]--;

            // If in-degree becomes 0, enqueue the vertex
            if (inDegree[ptr->dest] == 0)
                queue[rear++] = ptr->dest;

            ptr = ptr->next;
        }
    }

    printf("\n");

    free(inDegree);
    free(queue);
}

int main() {
    int numVertices, numEdges;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    struct Edge edges[numEdges];
    for (int i = 0; i < numEdges; i++) {
        printf("Enter source for edge %d: ", i + 1);
        scanf("%d", &edges[i].src);
        printf("Enter destination for edge %d: ", i + 1);
        scanf("%d", &edges[i].dest);
    }

    struct Graph *graph = createGraph(edges, numEdges, numVertices);

    printf("\nAdjacency List Representation:\n");
    printGraph(graph, numVertices);

    printf("\nTopological Sort: ");
    topologicalSort(graph, numVertices);

    return 0;
}
