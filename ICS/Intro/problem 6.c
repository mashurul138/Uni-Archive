#include <stdio.h>

int main()
{
    int age1, age2;

    printf("Please enter first person's age in years: ");
    scanf("%d", &age1);
    printf("Please enter second person's age in years: ");
    scanf("%d", &age2);
    printf("First person's age is: %d\n", age1);
    printf("Second person's age is: %d\n", age2);

    return 0;
}