// Write a program (WAP) that will print the factorial (N!) of a given number N. Please see the sample input output#include<stdio.h>

#include <stdio.h>
int main()
{
    int n, i;
    unsigned long long fact = 1;
    printf("Enter the number: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Error!");
    }
    else
    {
        for (i = 1; i <= n; ++i)
        {
            fact *= i;
        }
        printf("%d! = %d ", n, n);
        for (i = n - 1; i >= 0; i--)
        {
            if (i == 0)
            {
                break;
            }
            printf("x %d ", i);
        }
        printf("= %d", fact);
    }
    return 0;
}
