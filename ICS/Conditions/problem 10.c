// Program that will evaluate simple expressions of the form- <number1> <operator> <number2>; where operators are (+, - , *, /) And if the operator is “/”, then check if <number2> nonzero or not.
#include <stdio.h>

int main()
{
    float x, y, result;
    char c;

    printf("Enter the equation in the form <number1> <operator> <number2>: ");
    scanf("%f %c %f", &x, &c, &y);

    if (c == '+')
    {
        result = x + y;
        printf("Result: %f\n", result);
    }
    else if (c == '-')
    {
        result = x - y;
        printf("Result: %f\n", result);
    }
    else if (c == '*')
    {
        result = x * y;
        printf("Result: %f\n", result);
    }
    else if (c == '/')
    {
        if (y != 0)
        {
            result = x / y;
            printf("Result: %f\n", result);
        }
        else
            printf("Division: zero as divisor is not valid.\n");
    }
    else
        printf("Invalid operator.\n");

    return 0;
}