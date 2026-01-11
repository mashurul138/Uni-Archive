// Write a program that takes an integer number n as input and find out the sum of the following series up to n terms.
// 1 + 12 + 123 + 1234 + ��.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    int sum = 0, term = 0;
    for (int i = 1; i <= n; i++)
    {
        term = term * 10 + i;
        sum += term;
    }
    printf("%d", sum);
    return 0;
}
