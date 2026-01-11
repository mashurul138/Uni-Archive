// Program that will decide whether a number is positive or not.
#include <stdio.h>

int main()
{
    float x;
    printf("Enter a number: ");
    scanf("%f", &x);

    if (x > 0)
        printf("%.2f is a positive number.\n", x);
    else if (x < 0)
        printf("%.2f is a negative number.\n", x);
    else
        printf("The number is zero.\n");

    return 0;
}