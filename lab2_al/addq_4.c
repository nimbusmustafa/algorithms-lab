#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int isStrong(int n) {
    int original = n;
    int sum = 0;
    
    while (n > 0) {
        int digit = n % 10;
        sum += factorial(digit);
        n /= 10;
    }
    
    return (sum == original);
}

int deleteStrong(int arr[], int size, int index) {
    if (index >= size)
        return size;
    
    if (isStrong(arr[index])) {
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        return deleteStrong(arr, size - 1, index); 
    } else {
        return deleteStrong(arr, size, index + 1);
    }
}

int main() {
    int arr[] = {145, 10, 9, 40585, 7}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    printf("Original Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    size = deleteStrong(arr, size, 0); 
    printf("Array after deleting strong numbers: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
