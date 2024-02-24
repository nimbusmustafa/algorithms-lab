#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int a[], int n) {
    int i, j, temp, count = 0;
    for (i=0; i < n-1; i++) {
        for (j=0; j < n-i-1; j++) {
            count++;
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return count;
}

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

void main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count1 = bubbleSort(arr, n); 
    printf("operation count = %d\n", count1);
    printf("Sorted array: \n"); 
    printArray(arr, n); 
}