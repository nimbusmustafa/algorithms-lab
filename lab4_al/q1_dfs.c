#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int dest;
    struct Node *next;
};

struct Edge
{
    int src, dest;
};

struct Graph
{
    struct Node **head;
    int vertices;
    int *visited;
};

// Stack structure for DFS
struct Stack
{
    int top;
    int capacity;
    int *array;
};

struct Stack *createStack(int capacity)
{
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isStackEmpty(struct Stack *stack)
{
    return stack->top == -1;
}

void push(struct Stack *stack, int item)
{
    stack->array[++stack->top] = item;
}

int pop(struct Stack *stack)
{
    return stack->array[stack->top--];
}

void DFS(struct Graph *graph, int startVertex)
{
    struct Stack *stack = createStack(graph->vertices);

    push(stack, startVertex);

    while (!isStackEmpty(stack))
    {
        int currentVertex = pop(stack);
        if (graph->visited[currentVertex] == 1)
            continue;
        else
        {
            graph->visited[currentVertex] = 1;
            printf("Visited %d \n", currentVertex);
        }

        struct Node *temp = graph->head[currentVertex];
        while (temp != NULL)
        {
            int connectedVertex = temp->dest;

            if (graph->visited[connectedVertex] == 0)
            {
                push(stack, connectedVertex);
                // graph->visited[connectedVertex] = 1;
            }
            temp = temp->next;
        }
    }

    free(stack->array);
    free(stack);
}

struct Graph *createGraph(struct Edge edges[], int n, int vertices, int isDirected)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    graph->head = (struct Node **)malloc(vertices * sizeof(struct Node*));
    graph->visited = (int *)malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->head[i] = NULL;
        graph->visited[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->dest = dest;

        newNode->next = graph->head[src];
        graph->head[src] = newNode;

                if (!isDirected) // If undirected, add the reverse edge
        {
            struct Node *reverseNode = (struct Node *)malloc(sizeof(struct Node));
            reverseNode->dest = src;

            reverseNode->next = graph->head[dest];
            graph->head[dest] = reverseNode;
        }
    }
    

    return graph;
}

void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->vertices; i++)
    {
        struct Node *ptr = graph->head[i];
        printf("Adjacency list for vertex %d: ", i);
        while (ptr != NULL)
        {
            printf("%d ", ptr->dest);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    int n, vertices, isDirected;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &n);
     printf("Is the graph directed? (1/0): ");
    scanf(" %d", &isDirected);
    struct Edge edges[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter source for edge %d: ", i + 1);
        scanf("%d", &edges[i].src);
        printf("Enter destination for edge %d: ", i + 1);
        scanf("%d", &edges[i].dest);
    }

    struct Graph *graph = createGraph(edges, n, vertices, isDirected);

    printf("\nAdjacency List Representation:\n");
    printGraph(graph);

    printf("\nDFS Traversal \n");
    DFS(graph, 0);

    return 0;
}
