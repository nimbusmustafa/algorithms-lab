#include <stdio.h>
#include <stdlib.h>

void comparisonCountingSort(int arr[], int n, int count[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                count[j]++;
            } else {
                count[i]++;
            }
        }
    }

    int *temp = (int*)malloc(n * sizeof(int));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        temp[count[i]] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    free(temp);
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

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int *count = (int*)calloc(n, sizeof(int));
    if (count == NULL) {
        printf("Memory allocation failed.\n");
        free(arr);
        return 1;
    }

    comparisonCountingSort(arr, n, count);

    printf("Sorted array: ");
    printArray(arr, n);

    free(arr);
    free(count);

    return 0;
}
