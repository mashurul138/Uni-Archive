// Program that will take an integer of length one from the terminal and then display the digit in English.
#include <stdio.h>

int main()
{
    int x;
    printf("Enter a one digit integer: ");
    scanf("%d", &x);

    if (x == 0)
        printf("The number is zero.");
    else if (x == 1)
        printf("The number is one.");
    else if (x == 2)
        printf("The number is two.");
    else if (x == 3)
        printf("The number is three.");
    else if (x == 4)
        printf("The number is four");
    else if (x == 5)
        printf("The number is five.");
    else if (x == 6)
        printf("The number is six.");
    else if (x == 7)
        printf("The number is seven.");
    else if (x == 8)
        printf("The number is eight.");
    else if (x == 9)
        printf("The number is nine.");
    else
        printf("Invalid Input.");

    return 0;
}