#include <stdio.h>

int main()
{
    int x;
    float y;
    printf("Enter integer and floating number: ");
    scanf("%d %f", &x, &y);

    int asin_x = y;
    printf("Assignment: %f assigned to an int produces %d\n", y, asin_x);

    float asin_y = x;
    printf("Assignment: %d assigned to a float produces %f\n", x, asin_y);

    int cast_x = (int)y;
    printf("Type Casting: (int) %f produces %d\n", y, cast_x);

    float cast_y = (float)x;
    printf("Type Casting: (float) %d produces %f\n", x, cast_y);

    return 0;
}