#include <stdio.h>

int main()
{
    int x, y;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    y = x;
    printf("post-increment value of x: %d\n", x++);
    x = y;
    printf("pre-increment value of x: %d\n", ++x);
    x = y;
    printf("post-decrement value of x: %d\n", x--);
    x = y;
    printf("pre-decrement value of x: %d\n", --x);
    return 0;
}