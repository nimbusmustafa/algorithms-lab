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

void topologicalSortUtil(struct Graph *graph, int v, int visited[], int stack[], int *stackIndex) {
    visited[v] = 1;

    struct Node *temp = graph[v].head;
    while (temp != NULL) {
        if (!visited[temp->dest])
            topologicalSortUtil(graph, temp->dest, visited, stack, stackIndex);
        temp = temp->next;
    }

    stack[(*stackIndex)++] = v;
}

void topologicalSort(struct Graph *graph, int numVertices) {
    int *visited = (int *)malloc(numVertices * sizeof(int));
    int *stack = (int *)malloc(numVertices * sizeof(int));
    int stackIndex = 0;

    for (int i = 0; i < numVertices; i++)
        visited[i] = 0;

    for (int i = 0; i < numVertices; i++)
        if (!visited[i])
            topologicalSortUtil(graph, i, visited, stack, &stackIndex);

    // Print the result
    printf("Topological Sort: ");
    for (int i = stackIndex - 1; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");

    free(visited);
    free(stack);
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

    // Perform topological sort
    topologicalSort(graph, numVertices);

    return 0;
}
