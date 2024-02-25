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
    int vertices;
    int *visited;
};

// Queue structure for BFS
struct Queue {
    int front, rear, capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->rear = -1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isQueueEmpty(struct Queue* queue) {
    return queue->front == -1;
}

void enqueue(struct Queue* queue, int item) {
    if (isQueueEmpty(queue))
        queue->front = 0;
    queue->rear++;
    queue->array[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front++;
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;
    return item;
}

void BFS(struct Graph *graph, int startVertex) {
    // Create a queue for BFS
    int queue[1000];
    int front = -1;
    int rear = -1;

    graph->visited[startVertex] = 1;
    queue[++rear] = startVertex;

    while (front != rear) {
        int currentVertex = queue[++front];
        printf("Visited %d \n", currentVertex);

        struct Node *temp = graph->head[currentVertex].next;
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

struct Graph *createGraph(struct Edge edges[], int n, int vertices) {
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->head = (struct Node *)malloc(vertices * sizeof(struct Node));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->head[i].next = NULL;
        graph->visited[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;
        newNode->next = graph->head[src].next;
        graph->head[src].next = newNode;

        // Uncomment the following lines if the graph is undirected
        // struct Node *newNodeReverse = (struct Node *)malloc(sizeof(struct Node));
        // newNodeReverse->dest = src;
        // newNodeReverse->next = graph->head[dest].next;
        // graph->head[dest].next = newNodeReverse;
    }

    return graph;
}

void printGraph(struct Graph *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        struct Node *ptr = graph->head[i].next;
        printf("Adjacency list for vertex %d: ", i);
        while (ptr != NULL) {
            printf("%d ", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main() {
    int n, vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &n);

    struct Edge edges[n];
    for (int i = 0; i < n; i++) {
        printf("Enter source for edge %d: ", i + 1);
        scanf("%d", &edges[i].src);
        printf("Enter destination for edge %d: ", i + 1);
        scanf("%d", &edges[i].dest);
    }

    struct Graph *graph = createGraph(edges, n, vertices);

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    printf("\nBFS Traversal starting from vertex 2 (using explicit queue):\n");
    BFS(graph, 0);

    return 0;
}
