/*Program that will construct a menu for performing arithmetic operations. The user will give two real numbers (a, b) on which the arithmetic operations will be performed and an integer
number (1 <= Choice <= 4) as a choice. Choice-1, 2, 3, 4 are for performing addition, subtraction, multiplication, division respectively. If Choice-4 is selected, the program will check if b is nonzero. If the check is true, the program will ask for another choice (1 <= Case <=2), where Case-1, 2
evaluate quotient and reminder respectively. If the check is false, it will print an error message “Error: Divisor is zero” and halt.*/
#include <stdio.h>

int main()
{
    float a, b, result;
    int x, y;

    printf("Enter the 2 number: ");
    scanf("%f %f", &a, &b);

    printf("Menu:\n");
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
        if (b != 0)
        {
            printf("1. Quotient\n");
            printf("2. Remainder\n");
            printf("Enter your choice: ");
            scanf("%d", &y);

            if (y == 1)
            {
                result = a / b;
                printf("Quotient: %.2f\n", result);
            }
            else if (y == 2)
            {
                result = fmod(a, b);
                printf("Remainder: %.2f\n", result);
            }
            else
            {
                printf("Invalid choice for Case.\n");
            }
        }
        else
        {
            printf("Error: Divisor is zero.\n");
        }
    }
    else
    {
        printf("Invalid choice.\n");
    }

    return 0;
}
