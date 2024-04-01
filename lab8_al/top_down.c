#include <stdio.h>

void heapify(int arr[], int i) {
    int parent = i / 2;

    while (parent > 0 && arr[i] > arr[parent]) {
        int temp = arr[i];
        arr[i] = arr[parent];
        arr[parent] = temp;
        i = parent;
        parent = i / 2;
    }
}



void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    int arr[n + 1];  
    printf("Enter %d elements: ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        heapify(arr, i);  
    }

    printf("Heap: ");
    printArray(arr, n);


    return 0;
}
