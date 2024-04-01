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
void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void heapSort(int arr[], int n) {
    build_heap(arr, n);
    printf("original heap: ");
    printArray(arr, n);

    for (int i = n; i > 1; i--) {
        int temp = arr[i];
        arr[i] = arr[1];
        arr[1] = temp;
        heapify(arr, i - 1, 1);
    }
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

    heapSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
