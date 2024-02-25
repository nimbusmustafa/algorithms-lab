#include <stdio.h>
#include <stdlib.h>

#define N 100

struct Node {
    int dest;
    struct Node *next;
};

struct Edge {
    int src, dest;
};

struct Graph {
    struct Node *head[N];
    int vertices;
    int directed; // 0 for undirected, 1 for directed
};

struct Graph *createGraph(struct Edge edges[], int n, int e, int directed) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = n;
    graph->directed = directed;

    for (int i = 0; i < n; i++) {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < e; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;

        newNode->next = graph->head[src];
        graph->head[src] = newNode;

        if (!directed) {
            // For undirected graph, add reverse edges
            newNode = (struct Node *)malloc(sizeof(struct Node));
            newNode->dest = src;
            newNode->next = graph->head[dest];
            graph->head[dest] = newNode;
        }
    }

    return graph;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node *ptr = graph->head[i];
        while (ptr != NULL) {
            printf("(%d -> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

int isBipartiteDFS(struct Graph *graph, int v, int color[], int c) {
    color[v] = c;

    struct Node *ptr = graph->head[v];
    while (ptr != NULL) {
        int u = ptr->dest;

        if (color[u] == -1) {
            if (!isBipartiteDFS(graph, u, color, 1 - c))
                return 0;
        } else if (color[u] == color[v]) {
            return 0;
        }

        ptr = ptr->next;
    }

    return 1;
}

int isBipartiteBFS(struct Graph *graph, int src) {
    int color[N];
    for (int i = 0; i < graph->vertices; i++) {
        color[i] = -1;
    }

    color[src] = 1;

    int queue[N];
    int front = -1, rear = -1;
    queue[++rear] = src;

    while (front != rear) {
        int u = queue[++front];

        struct Node *ptr = graph->head[u];
        while (ptr != NULL) {
            int v = ptr->dest;

            if (color[v] == -1) {
                color[v] = 1 - color[u];
                queue[++rear] = v;
            } else if (color[v] == color[u]) {
                return 0;
            }

            ptr = ptr->next;
        }
    }

    return 1;
}

int main() {
    int n, e;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    int directed;
    printf("Is the graph directed? (1 for Yes, 0 for No): ");
    scanf("%d", &directed);

    printf("Enter the number of edges: ");
    scanf("%d", &e);

    struct Edge edges[N];
    for (int i = 0; i < e; i++) {
        printf("Enter source for edge %d: ", i + 1);
        scanf("%d", &edges[i].src);
        printf("Enter destination for edge %d: ", i + 1);
        scanf("%d", &edges[i].dest);
    }

    struct Graph *graph = createGraph(edges, n, e, directed);

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    int colorDFS[N], colorBFS[N];

    for (int i = 0; i < N; i++) {
        colorDFS[i] = -1;
        colorBFS[i] = -1;
    }

      printf("\nDFS Bipartite Check: %s\n", isBipartiteDFS(graph, 0, colorDFS, 0) ? "Yes" : "No");
    printf("BFS Bipartite Check: %s\n", isBipartiteBFS(graph, 0) ? "Yes" : "No");

    return 0;
}

