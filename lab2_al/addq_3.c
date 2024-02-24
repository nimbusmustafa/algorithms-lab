#include <stdio.h>

int fibonacci(int n, int memo[]) {
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;
    if (memo[n] != -1)
        return memo[n];
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    int memo[n + 1];
    for (int i = 0; i <= n; i++)
        memo[i] = -1;

    printf("The %dth Fibonacci number is: %d\n", n, fibonacci(n, memo));
    
    return 0;
}
