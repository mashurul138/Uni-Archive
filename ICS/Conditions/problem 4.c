/*Program that will check whether a triangle is valid or not, when the three angles
(angle value should be such that, 0 < value < 180) of the triangle are entered through the keyboard.*/
#include <stdio.h>

int main()
{
    int x, y, z, sum;
    printf("Enter 3 angle value: ");
    scanf("%d %d %d", &x, &y, &z);
    sum = x + y + z;
    if (0 < x && x < 180 && 0 < y && y < 180 && 0 < z && z < 180 && sum == 180)
        printf("Yes.");
    else
        printf("No.");
    return 0;
}