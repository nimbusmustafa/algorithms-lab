#include <stdio.h>

int sqrtt(int n) {
    int left = 0, right = n, answer = 0, middle = 0;

    while (left <= right) {
        middle = (left + right) / 2;

        if (middle * middle == n) {
            return middle;
        } else if (middle * middle < n) {
            left = middle + 1;
            answer = middle;
        } else {
            right = middle - 1;
        }
    }
    return answer;
}

int main() {
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Floor square root of %d is %d\n", n, sqrtt(n));
    return 0;
}
