#include <stdio.h>
#include <stdlib.h>

#define N 6

typedef struct Node{
    int dest;
    struct Node *next;
}Node;

typedef struct Edge{
    int src,dest;
}Edge;

void init_matrix(int arr[][N]){
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            arr[i][j] = 0;
}

void addEdge(int arr[][N], int src, int dest){
    arr[src][dest]=1;
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

int main(){
    int adjMatrix[N][N];

    init_matrix(adjMatrix);
    struct Edge edges[N];
    for (int i = 0; i < N; i++)
    {
        printf("enter source");
        scanf("%d", &edges[i].src);
        printf("enter dest");
        scanf("%d", &edges[i].dest);
        addEdge(adjMatrix, edges[i].src, edges[i].dest);
    }
        printAdjMatrix(adjMatrix);
        return 0;

}