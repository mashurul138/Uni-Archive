#include <stdio.h>

int main()
{
    float a, b;

    printf("Enter the values: ");
    scanf("%f %f", &a, &b);
    float result = (3.31 * a * a + 2.01 * b * b * b) / (7.16 * b * b + 2.01 * a * a * a);
    printf("The result of the equation is: %f\n", result);

    return 0;
}