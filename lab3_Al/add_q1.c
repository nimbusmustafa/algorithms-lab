#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void initializeMatrix(int rows, int cols, int matrix[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 10; // Assigning random values for simplicity
        }
    }
}

void matrixMultiply(int rowsA, int colsA, int A[rowsA][colsA],
                    int rowsB, int colsB, int B[rowsB][colsB],
                    int result[rowsA][colsB]) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void inputMatrix(int rows, int cols, int matrix[rows][cols]) {
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    printf("Enter the dimensions of matrix A (rows columns): ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter the dimensions of matrix B (rows columns): ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication is not possible with these dimensions.\n");
        return 1;
    }

    int matrixA[rowsA][colsA];
    int matrixB[rowsB][colsB];
    int resultMatrix[rowsA][colsB];

    inputMatrix(rowsA, colsA, matrixA);
    inputMatrix(rowsB, colsB, matrixB);
    
    matrixMultiply(rowsA, colsA, matrixA, rowsB, colsB, matrixB, resultMatrix);

    if (rowsA <= 10 && colsB <= 10) {
        printf("Result Matrix:\n");
        for (int i = 0; i < rowsA; i++) {
            for (int j = 0; j < colsB; j++) {
                printf("%d\t", resultMatrix[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
