#include <stdio.h>

int main()
{
    int a, b, x, y;
    printf("Enter two number: ");
    scanf("%d %d", &x, &y);
    a = x;
    b = y;
    printf("Multiplication: %d\n", x *= y);
    x = a;
    y = b;
    printf("Division: %d", x /= y);
    return 0;
}