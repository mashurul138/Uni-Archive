#include <stdio.h>

int main()
{
    int a, b, x, y;
    printf("Enter two integer: ");
    scanf("%d %d", &x, &y);
    a = x;
    b = y;
    x += y;
    printf("incremented value: %d\n", x);
    x = a;
    y = b;
    x -= y;
    printf("decremented value: %d", x);
    return 0;
}