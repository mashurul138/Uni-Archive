// Write a program (WAP) that will find nCr where n >= r; n and r are integers.

#include <stdio.h>

int fact(int z)
{
    int f = 1, i;
    if (z == 0)
    {
        return (f);
    }
    else
    {
        for (i = 1; i <= z; i++)
        {
            f = f * i;
        }
    }
    return (f);
}

int main()
{
    int n, r, result;
    printf("Enter the value of n and r: ");
    scanf("%d%d", &n, &r);

    result = fact(n) / (fact(r) * fact(n - r));
    printf("%d", result);

    return 0;
}