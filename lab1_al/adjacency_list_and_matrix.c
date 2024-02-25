#include <stdio.h>
#include <stdlib.h>

#define N 6

struct Graph
{
    struct Node *head[N];
};

struct Node
{
    int dest;
    struct Node *next;
};

struct Edge
{
    int src, dest;
};

struct Graph *createGraph(struct Edge edges[], int n)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));

    for (int i = 0; i < N; i++)
    {
        graph->head[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;

        newNode->next = graph->head[src];

        graph->head[src] = newNode;
    }

    return graph;
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < N; i++)
    {
        struct Node *ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

void init(int arr[][N])
{
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][N], int src, int dest)
{
    arr[src][dest] = 1;
}

void printAdjMatrix(int arr[][N])
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    int adjMatrix[N][N];

    init(adjMatrix);
    struct Edge edges[N];
    for (int i = 0; i < N; i++)
    {
        printf("enter source");
        scanf("%d", &edges[i].src);
        printf("enter dest");
        scanf("%d", &edges[i].dest);
        addEdge(adjMatrix, edges[i].src, edges[i].dest);
    }

    int n = sizeof(edges) / sizeof(edges[0]);

    struct Graph *graph = createGraph(edges, n);
    printGraph(graph);
    printAdjMatrix(adjMatrix);
    return 0;
}