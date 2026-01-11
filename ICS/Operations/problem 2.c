#include <stdio.h>
int main()
{
    float r;
    printf("Enter the radius value: ");
    scanf("%f", &r);
    float cir = 2 * 3.1416 * r;
    printf("circumference: %f", cir);
    return 0;
}