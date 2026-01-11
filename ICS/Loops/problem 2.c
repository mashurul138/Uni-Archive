// Write a program (WAP) that will print following series up to Nth terms. 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31 ��.

#include <stdio.h>
int main()
{
    int i, x;
    printf("Enter a number: ");
    scanf("%d", &x);
    for (i = 1; i < x; i += 2)
    {
        printf("%d,", i);
    }
    return 0;
}