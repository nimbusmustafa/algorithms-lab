#include <stdio.h>

double power(double a, int n) {
    if (n == 0) {
        return 1.0;
    }

    if (n % 2 == 0) {
        double halfPower = power(a, n / 2);
        return halfPower * halfPower;
    }
    else {
        return a * power(a, n - 1);
    }
}

int main() {
    double a;
    int n;

    printf("Enter the base (a): ");
    scanf("%lf", &a);

    printf("Enter the exponent (n): ");
    scanf("%d", &n);

    double result = power(a, n);
    printf("%.2f raised to the power of %d is %.6f\n", a, n, result);

    return 0;
}
