/*Program for “Guessing Game”:
Player-1 picks a number X and Player-2 has to guess that number within N = 3 tries. For each wrong guess by Player-2, the program prints “Wrong, N-1 Chance(s) Left!”
If Player-2 successfully guesses the number, the program prints “Right, Player-2 wins!” and stops allowing further tries (if any left). Otherwise after the completion of N = 3 wrong tries, the program prints “Player-1 wins!” and halts.*/
#include <stdio.h>

int main()
{
    int x, n, maxTries = 3, flag = 0;

    printf("Player-1, enter your number: ");
    scanf("%d", &x);

    printf("Player-2, try to guess the number: ");
    scanf("%d", &n);

    if (n == x)
    {
        printf("Right, Player-2 wins!\n");
    }
    else
    {
        printf("Wrong, %d Chance(s) Left!\n", maxTries - 1);

        maxTries--;

        printf("Player-2, try to guess the number: ");
        scanf("%d", &n);

        if (n == x)
        {
            printf("Right, Player-2 wins!\n");
            flag = 1;
        }
        else
        {
            printf("Wrong, %d Chance(s) Left!\n", maxTries - 1);
            maxTries--;
        }
    }

    if (flag == 0 && maxTries > 0)
    {
        printf("Player-2, try to guess the number: ");
        scanf("%d", &n);

        if (n == x)
        {
            printf("Right, Player-2 wins!\n");
        }
        else
        {
            printf("Player-1 wins!\n");
        }
    }
    else if (flag == 0)
    {
        printf("Player-1 wins!\n");
    }

    return 0;
}