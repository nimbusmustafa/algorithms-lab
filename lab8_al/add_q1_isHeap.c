#include <stdio.h>

int isHeap(int arr[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        if (2 * i <= n && arr[2 * i] > arr[i])
            return 0;

        if (2 * i + 1 <= n && arr[2 * i + 1] > arr[i])
            return 0;
    }

    return 1;
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);


    int arr[n + 1];  
    printf("Enter %d elements: ", n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    if (isHeap(arr, n))
        printf("The array is a heap.\n");
    else
        printf("The array is not a heap.\n");

    return 0;
}
