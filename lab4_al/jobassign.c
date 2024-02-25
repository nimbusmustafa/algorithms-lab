#include<stdio.h>
#include<stdlib.h>


void swap(int *a, int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void assign(int arr[][10], int index[], int low, int high, int *res, int *cost) 
{
    if (low == high) {
        int x = 0;
        for (int i = 0; i <=  high; i++) 
        {
            x += arr[i][index[i]];
        }
        if (x < *cost) 
        {
            *cost = x;
            for (int i = 0; i <= high; i++) 
            {
                res[i] = index[i];
            }
        }
    }
    else {
        for (int i = low; i <= high; i++) 
        {
            swap(&index[low], &index[i]);
            assign(arr, index, low + 1, high, res, cost);
            swap(&index[low], &index[i]);   // swap back, cost already found
        }
    }
}

void main() 
{
    printf("Enter n : ");
    int n;
    scanf("%d", &n);
    int arr[n][n];
    int index[n];
    for (int i = 0; i < n; i++) 
    {
        index[i] = i;
        printf("Enter costs for employee %d: ", (i + 1));
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Matrix : \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }    

    int cost = 1000000;
    int *res = malloc(n * sizeof(int));
    assign(arr, index, 0, n - 1, res, &cost);

    printf("Assigned Jobs:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Job %d by person %d\n", res[i], i + 1);
    }
    printf("Total cost = %d\n", cost);
}
