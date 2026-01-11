#include <stdio.h>
#include <float.h>
#include <limits.h>

int main()
{
    long int myLongInt = LONG_MAX;
    long long int myLongLongInt = LLONG_MAX;
    long double myLongDouble = LDBL_MAX;
    short int myShortInt = SHRT_MAX;

    printf("The long int value: %ld\n", myLongInt);
    printf("The long long int value: %lld\n", myLongLongInt);
    printf("The long double value: %.1Le\n", myLongDouble);
    printf("The short int value: %hd\n", myShortInt);

    return 0;
}