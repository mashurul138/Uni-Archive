/*Program that will construct a menu for performing arithmetic operations. The user will give two real numbers (a, b) on which the arithmetic operations will be performed
and an integer number (1 <= Choice <= 4) as a choice. Choice-1, 2, 3, 4 are for performing addition, subtraction, multiplication, division (quotient) respectively.*/
#include <stdio.h>

int main()
{
    int c, d;
    float a, b;
    printf("Enter 2 real number: ");
    scanf("%f %f", &a, &b);
    printf("Enter option: \n");
    printf("1. Summation\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Quotient\n");
    printf("Enter option: ");
    scanf("%d", &c);

    if (c == 1)
    {
        d = a + b;
        printf("summation is: %d", d);
    }
    else if (c == 2)
    {
        d = a - b;
        printf("subtraction is: %d", d);
    }
    else if (c == 3)
    {
        d = a * b;
        printf("multiplication is: %d", d);
    }
    else if (c == 4)
    {
        d = a / b;
        printf("Quotient is: %d", d);
    }
    else
    {
        printf("not a valid operators.");
    }

    return 0;
}