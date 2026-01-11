#include <stdio.h>

int main()
{

    int a;
    int b = 42;
    int c = 10, d = 20, e = 30;
    int f = 5, g = 5, h = 5;
    printf("a) Uninitialized Variable: %d\n", a);
    printf("b) Initialized Variable: %d\n", b);
    printf("c) Multiple Variables with Different Values: %d, %d, %d\n", c, d, e);
    printf("d) Multiple Variables with the Same Value: %d, %d, %d\n", f, g, h);

    return 0;
}