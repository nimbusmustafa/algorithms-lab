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


void deleteElement(int arr[], int n, int value) {
    int index = -1;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == value) {
            index = i;
            break;
        }
    }

    if (index == -1)
        return;

    arr[index] = arr[n];

    heapify(arr, n-1, index);
}

void printArray(int arr[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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

    int value;
    printf("Enter the value to delete: ");
    scanf("%d", &value);

    deleteElement(arr, n, value);

    printf("Heap after deleting %d: ", value);
    printArray(arr, n-1);

    return 0;
}