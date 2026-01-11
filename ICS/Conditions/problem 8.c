// Program that will decide whether a year is leap year or not.
#include <stdio.h>

int main()
{
    int x;
    printf("Enter a year: ");
    scanf("%d", &x);

    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
        printf("%d is a leap year.", x);
    else
        printf("%d is not a leap year.", x);

    return 0;
}