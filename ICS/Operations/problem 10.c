#include <stdio.h>

int main()
{
    int a, b, c;

    printf("Enter the values: ");
    scanf("%d %d %d", &a, &b, &c);

    int x = (a + b) <= 80;
    int y = !(a + c);
    int z = (a != 0);

    printf("a): %d\n", x);
    printf("b): %d\n", y);
    printf("c): %d\n", z);
    return 0;
}