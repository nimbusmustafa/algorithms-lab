#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int k = i;
    int v = arr[k];
    int heap = 0; 

    while (!heap && 2 * k <= n) {
        int j = 2 * k;
        if (j < n && arr[j] < arr[j + 1])
            j = j + 1;
        if (v >= arr[j])
            heap = 1; 
        else {
            arr[k] = arr[j];
            k = j;
        }
    }
    arr[k] = v;
}

void build_heap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}

void findSmallestElement(int arr[], int * n) {
    int smallest = arr[*n];
int i;
    for ( i = *n / 2 + 1; i <= *n; i++) {
        if (arr[i] < smallest) {
            smallest = arr[i];
            arr[i] = arr[*n];


        }
    }

    (*n)--;

    heapify(arr, *n, i);
}

int main() {
    int arr[100];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    build_heap(arr, n);

     findSmallestElement(arr, &n);


    printf("Heap after deleting the smallest element: ");
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
