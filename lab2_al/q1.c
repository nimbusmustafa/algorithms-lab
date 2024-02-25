#include <stdio.h>

int GCD(int a, int b, int *p)
{
    
    int i, c;
    c = a >= b ? b : a;
    for (i = c; i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {

            return i;
        }
        (*p)++;
    }
}

int main()
{
    printf("Enter two numbers");
    int a, b, opcount = 1;
    // int *p=&opcount;
    scanf("%d%d", &a, &b);
    int ans = GCD(a, b, &opcount);
    printf("GCD = %d\n", ans);
    printf("opcount= %d", opcount);
    return 0;
}