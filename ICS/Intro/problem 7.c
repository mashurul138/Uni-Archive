#include <stdio.h>

int main()
{
    int p;
    float q;
    char r;

    printf("Please enter an integer: ");
    scanf("%d", &p);
    printf("Please enter a floating point number: ");
    scanf("%f", &q);
    printf("Please enter a character: ");
    scanf(" %c", &r);
    printf("The integer value: %d\n", p);
    printf("The floating point value: %f\n", q);
    printf("The character value: %c\n", r);

    return 0;
}