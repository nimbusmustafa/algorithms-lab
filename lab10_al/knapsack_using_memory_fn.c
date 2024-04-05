#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) { return (a > b) ? a : b; }

int knapsack(int W, int **table, int n, int *weights, int *profits)
{
    int value; 
    
            if(table[n][W]<0){
                if(W<weights[n-1]){
                   value=knapsack( W, table, n-1, weights, profits);
                }
                else{
                    value=max(knapsack(W, table, n-1, weights, profits), knapsack(W-weights[n-1], table, n-1, weights, profits)+profits[n-1]);
                }
                table[n][W]=value;
            }
        
    
    return table[n][W];
}

int main() {
    int W, n;
    printf("Enter the number of objects: ");
    scanf("%d", &n);

    int *weights = (int *)malloc(n * sizeof(int));
    printf("Enter the weights of %d objects: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int *profits = (int *)malloc(n * sizeof(int));
    printf("Enter the profits of %d objects: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &profits[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &W);

    int **table = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++) {
        table[i] = (int *)malloc((W + 1) * sizeof(int));
    }

    for (int j = 0; j <= W; j++) {
        table[0][j] = 0;
    }
    for (int i = 0; i <= n; i++) {
        table[i][0] = 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            table[i][j]=-1;
        }
    }
    int answer = knapsack(W, table, n, weights, profits);
    printf("Answer: %d\n", answer);


    return 0;
}
