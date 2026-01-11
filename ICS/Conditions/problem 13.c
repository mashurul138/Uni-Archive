/*Program that will construct a menu for performing arithmetic operations. The user will give two real numbers (a, b) on which the arithmetic operations will be
performed and an integer number (1 <= Choice <= 4) as a choice. Choice-1, 2, 3, 4 are for performing addition,subtraction, multiplication, division respectively.
If Choice-4 is selected, again the program will ask for another choice (1 <= Case <=2), whereCase-1, 2 evaluate quotient and remainder respectively.*/
#include <stdio.h>

int main()
{
    float a, b, result;
    int x, y;

    printf("Enter the 2 number: ");
    scanf("%f %f", &a, &b);

    printf("\nMenu:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");

    printf("Enter your choice: ");
    scanf("%d", &x);

    if (x == 1)
    {
        result = a + b;
        printf("Result: %.2f\n", result);
    }
    else if (x == 2)
    {
        result = a - b;
        printf("Result: %.2f\n", result);
    }
    else if (x == 3)
    {
        result = a * b;
        printf("Result: %.2f\n", result);
    }
    else if (x == 4)
    {
        printf("1. Quotient\n");
        printf("2. Remainder\n");
        printf("Enter your choice: ");
        scanf("%d", &y);

        if (y == 1)
        {
            if (b != 0)
            {
                result = a / b;
                printf("Quotient: %.2f\n", result);
            }
            else
            {
                printf("Error: Divisor is zero.\n");
            }
        }
        else if (y == 2)
        {
            if (b != 0)
            {
                result = fmod(a, b);
                printf("Remainder: %.2f\n", result);
            }
            else
            {
                printf("Error: Divisor is zero.\n");
            }
        }
        else
        {
            printf("Invalid choice for Case.\n");
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}