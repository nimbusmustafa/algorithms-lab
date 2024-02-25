#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node *next;
} node;

typedef struct Edge {
    int src, dest;
} edge;

void init_matrix(int **arr, int N) {
    for (int i = 0; i < N; i++) {
        arr[i] = (int *)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            arr[i][j] = 0;
        }
    }
}

void addEdge(int **arr, int src, int dest) {
    arr[src][dest] = 1;
}

void printAdjMatrix(int **arr, int N) {
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int N;
    printf("Enter the number of vertices: ");
    scanf("%d", &N);

    int **adjMatrix = (int **)malloc(N * sizeof(int *));
    init_matrix(adjMatrix, N);

    struct Edge edges[N];
    for (int i = 0; i < N; i++) {
        printf("Enter source: ");
        scanf("%d", &edges[i].src);
        printf("Enter dest: ");
        scanf("%d", &edges[i].dest);
        addEdge(adjMatrix, edges[i].src, edges[i].dest);
    }

    printAdjMatrix(adjMatrix, N);

    for (int i = 0; i < N; i++) {
        free(adjMatrix[i]);
    }
    free(adjMatrix);

    return 0;
}
