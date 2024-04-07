#include<stdio.h>
#include<stdlib.h>
struct Graph{
    struct node **head;
};
struct node{
    int dest;
    struct node *next;
};

struct Edge{
    int src, dest;
};

struct Graph *createGraph(int V, int E, struct Edge edges[]){
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->head = (struct node **)malloc(V*sizeof(struct node *));
    for(int i=0;i<V;i++){
      graph->head[i]=NULL;
    }
      for (int i = 0; i < E; i++)
    {
        int src = edges[i].src;
        int dest = edges[i].dest;
        struct node *Newnode=(struct node*)malloc(sizeof(struct node));
        Newnode->dest=dest;
        Newnode->next=graph->head[src];
        graph->head[src]=Newnode;
  
}

return graph;}

void printGraph(struct Graph *graph, int V)
{
    for (int i = 0; i < V; i++)
    {
        struct node *ptr = graph->head[i];
        while (ptr != NULL)
        {
            printf("(%d —> %d)\t", i, ptr->dest);
            ptr = ptr->next;
        }

        printf("\n");
    }
}
int main(){
    int V; int E;
    printf("enter no of vertices: \n");
    scanf("%d", &V);
        printf("enter no of edges: \n");
    scanf("%d", &E);
    struct Edge edges[E];

    for (int i = 0; i < E; i++)
    {
        printf("enter source");
        scanf("%d", &edges[i].src);
        printf("enter dest");
        scanf("%d", &edges[i].dest);
    }
        struct Graph *graph = createGraph(V,E,edges);
    printGraph(graph, V);
    return 0;
}