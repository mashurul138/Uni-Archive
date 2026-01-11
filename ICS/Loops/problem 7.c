// Write a program (WAP) that will run and show keyboard inputs until the user types an �A�at the keyboard.
#include <stdio.h>
int main()
{
    char input;
    int n = 1;
    while (1)
    {
        scanf(" %c", &input);
        if (input == 'A')
            break;
        printf("Input %d: %c\n", n, input);
        n++;
    }
    return 0;
}
