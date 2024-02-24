#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void bubbleSort(char arr[][100], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char temp[100];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void printStrings(char arr[][100], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    int n;

    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char strings[n][100];

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }

    bubbleSort(strings, n);

    printf("Sorted strings:\n");
    printStrings(strings, n);

    return 0;
}
