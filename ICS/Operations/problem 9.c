#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter values: ");
    scanf("%d %d %d", &a, &b, &c);
    int X = a - b / 3 + c * 2 - 1;
    int Y = a - (b / (3 + c) * 2) - 1;
    int Z = a - ((b / 3) + c * 2) - 1;
    printf("X = %d\n", X);
    printf("Y = %d\n", Y);
    printf("Z = %d\n", Z);
    return 0;
}