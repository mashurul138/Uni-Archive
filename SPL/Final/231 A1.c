#include <stdio.h>

int is_prime (int x)
{
    for (int i = 2; i < x/2; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int digit_sum (unsigned int x)
{
    int sum = 0;
    while (x != 0)
    {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int is_superprime (int x)
{
    if (!is_prime(x))
        return 0;
    int sum = digit_sum(x);
    if(is_prime(sum) == 1)
    {
        return 1;
    }
}

int main()
{
    int num1, num2;
    printf("Enter 2 number: ");
    scanf("%d %d", &num1, &num2);
    for (int i = num1; i <= num2; i++)
    {
        if (is_superprime(i))
            printf("%d\n",i);
    }

    return 0;
}
