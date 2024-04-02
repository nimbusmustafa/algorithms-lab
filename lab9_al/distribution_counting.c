#include <stdio.h>
#include <stdlib.h>

void distributionCountingSort(int arr[], int n, int range) {
    int *count = (int *)malloc(range * sizeof(int));


    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    int *output = (int *)malloc(n * sizeof(int));


    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        // count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }


}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    printf("Enter the elements: ");
    int maxElement = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }
    int range = maxElement + 1;

    distributionCountingSort(arr, n, range);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);

    return 0;
}
