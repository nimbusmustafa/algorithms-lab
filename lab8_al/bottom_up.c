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


void printHeap(int arr[], int n, int index, int level) {
    if (index <= n) {
        printHeap(arr, n, 2 * index + 1, level + 1);
        printf("%*s%d\n", 4 * level, "", arr[index]);
        printHeap(arr, n, 2 * index, level + 1);
    }
}

int main() {
    int arr[100]; 
    int n;

    printf("Enter the number of elements in the heap: ");
    scanf("%d", &n);

    printf("Enter the elements of the heap: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    build_heap(arr, n);

    printf("Heap as a tree:\n");
    printHeap(arr, n, 1, 0);

    return 0;
}
