#include<stdio.h>
#include<stdlib.h>
#define INF 99999 

void warshall(int **table, int n){
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(table[i][k]+table[k][j] < table[i][j]){
                    table[i][j]=table[i][k]+table[k][j];
                }
            }
        }
    }
}
int main(){
    int n, e ,u, v,w,i,j;
    printf("\nEnter no of vertices: ");
    scanf("%d", &n);
    int  **table=(int **)malloc(n*sizeof(int *));
    for (i=0;i<n;i++){
        table[i]=(int*)malloc(n*sizeof(int));
        for(j=0;j<n;j++){
            table[i][j]=INF;
        }
    }
    printf("\nEnter no of edges: ");
    scanf("%d",&e);
    for (i = 0; i < e; i++) {
    printf("Enter the end vertices of edge and weight %d: ", i + 1);
    scanf("%d %d %d", &u, &v, &w);
    table[u][v] = w;
    }
    printf("\nMatrix of input data:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", table[i][j]);
        printf("\n");
    }
        warshall(table, n);

    printf("\nTransitive closure:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d\t", table[i][j]);
        printf("\n");
    }



    return 0;
}
