// Write a program (WAP) that will print following series up to Nth terms. 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, ��.

#include <stdio.h>
int main()
{
    int i, x;
    printf("Enter a number: ");
    scanf("%d", &x);
    for (i = 1; i <= x; ++i)
    {
        if (i % 2 == 0)
        {
            printf("0,");
        }
        else
        {
            printf("1,");
        }
    }
    return 0;
}