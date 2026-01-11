// Write a program (WAP) that will take N numbers as inputs and compute their average.

#include <stdio.h>
int main()
{
    int i, x;
    float sum = 0, n, avg;
    printf("How many values you want to avarage: ");
    scanf("%d", &x);
    for (i = 1; i <= x; ++i)
    {
        printf("Enter %d number: ", i);
        scanf("%f", &n);
        sum += n;
    }
    avg = sum / x;
    printf("AVG of %d input: %f", x, avg);
    return 0;
}