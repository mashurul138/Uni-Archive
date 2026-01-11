/*Write a program (WAP) for the described scenario:
Player-1 picks a number X and Player-2 has to guess that number within N tries. For each wrong guess by Player-2, the program prints �Wrong, N-1 Choice(s) Left!�
If Player-2 at any time successfully guesses the number, the program prints �Right, Player-2 wins!� and terminates right away.
Otherwise after the completion of N wrong tries, the program prints �Player-1 wins!� and halts.*/

#include <stdio.h>
int main()
{
    int i, x, y, z;
    printf("Enter any number:");
    scanf("%d", &x);
    printf("How many times: ");
    scanf("%d", &y);
    for (i = 0; i < y; i++)
    {
        printf("Guess the number:");
        scanf("%d", &z);
        if (z == x)
        {
            printf("Right, Player-2 wins!\n");
            break;
        }
        else
        {
            printf("Wrong, %d Choice(s) Left!\n", y - i - 1);
        }
    }
    if (z != x)
    {
        printf("Player-1 wins!\n");
    }
    return 0;
}