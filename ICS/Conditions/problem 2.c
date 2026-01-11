// Program that will decide whether a number is even or odd.
#include <stdio.h>

int main()
{
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);

    if (x % 2 == 0)
        printf("%d is even.", x);
    else
        printf("%d is odd.", x);
    return 0;
}