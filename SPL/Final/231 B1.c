
#include <stdio.h>

int is_prime (int x)
{
    for (int i = 2; i <= x/2; i++)
    {
        if (x % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int power_of_2 (int x)
{
    if (x < 1)
    {
        return 0;
    }
    else if (x == 1)
    {
        return 1;
    }
    else if (x % 2 != 0)
    {
        return 0;
    }
    else
    {
        return power_of_2(x / 2);
    }

}

int is_mersenne (int a)
{
    if(!is_prime(a))
        return 0;

    int r = power_of_2(a+1);
        if (r != 0)
        {
            return 1;
        }
    return 0;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int m = is_mersenne(num);
    if (m == 1)
    {
        printf("Yes.\n");
    }
    else
    {
        printf("No.\n");
    }
    return 0;
}
