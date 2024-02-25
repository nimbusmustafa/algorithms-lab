#include <stdio.h>

int isPrime(int num, int *p)
{
 (*p)++;
    int i;
    for (i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int GCD(int a, int b, int*p)
{
    int i, product = 1;
    int c = a >= b ? b : a;
    for (i = 2; i <= c; i++)
    {

        if (isPrime(i, p))
        {
            if (a % i == 0 && b % i == 0)
            {
                product *= i;
                a /= i;
                b /= i;
                if (a == b && a != 0)
                {
                    return product * a;
                }
                else if (a == 1)
                {
                    return product;
                }
                else if (b == 1)
                {
                    return product;
                }
                else
                {
                    return product * GCD(a, b, p);
                }
            }
        }
    }
    return product;
}

int main()
{
    printf("Enter two numbers");
    int a, b;
    int p=1;
    scanf("%d%d", &a, &b);
    int ans = GCD(a, b , &p);
    printf("GCD = %d", ans);
    printf("opcount= %d", p);

    return 0;
}