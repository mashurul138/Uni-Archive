// Write a program (WAP) that will print following series up to Nth terms.1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, ��.

#include <stdio.h>
int main()
{
    int i, x;
    printf("Enter a number: ");
    scanf("%d", &x);
    for (i = 1; i < x; i++)
    {
        printf("%d,", i);
    }
    printf("%d", x);
    return 0;
}