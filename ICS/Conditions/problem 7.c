// Program that will take two numbers X & Y as inputs and decide whether X is greater than/less than/equal to Y.
#include <stdio.h>

int main()
{
    int x, y;
    printf("Enter 2 number: ");
    scanf("%d %d", &x, &y);

    if (x > y)
        printf("%d is greater than %d", x, y);
    else if (x < y)
        printf("%d is less than %d", x, y);
    else
        printf("%d is equals to %d", x, y);
    return 0;
}