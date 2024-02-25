#include <stdio.h>

int countWaysToTile(int n) {
    if (n <= 0 || n == 1 || n==2) {
        return n;
    }

    return countWaysToTile(n - 1) + countWaysToTile(n - 2);
}

int main() {
    int n;

    printf("Enter the length of the board (n): ");
    scanf("%d", &n);

    int ways = countWaysToTile(n);
    printf("Number of ways to tile a 2 x %d board: %d\n", n, ways);

    return 0;
}
