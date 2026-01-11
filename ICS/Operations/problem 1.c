#include <stdio.h>
int main()
{
    int x, y;
    printf("Enter two number: ");
    scanf("%d %d", &x, &y);
    printf("Addition: %d\nSubtraction: %d\nMultiplication: %d\nQuotient : %d\nReminder: %d", x + y, x - y, x * y, x / y, x % y);
    return 0;
}