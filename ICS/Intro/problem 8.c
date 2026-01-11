#include <stdio.h>

int main()
{
    int x, y, z;
    printf("Please enter three integer numbers: ");
    scanf("%d %*d %d", &x, &z);
    printf("First Value = %d, Last Value = %d\n", x, z);

    return 0;
}