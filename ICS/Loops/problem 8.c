// Write a program (WAP) that will reverse the digits of an input integer.
#include <stdio.h>
int main()
{
    int num, temp, r, sum = 0;
    printf("Enter numbers:");
    scanf("%d", &num);

    temp = num;

    while (temp != 0)
    {
        r = temp % 10;
        sum = sum * 10 + r;
        temp = temp / 10;
    }
    printf("Reverse of the numbers: %d\n", sum);
    return 0;
}
