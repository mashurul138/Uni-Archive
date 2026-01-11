// Program that will categorize a single character that is entered at the terminal, whether it is an alphabet, a digit or a special character.
#include <stdio.h>

int main()
{
    char x;
    printf("Enter input: ");
    scanf("%c", &x);

    if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
        printf("%c is Alphabet.", x);
    else if (x >= '0' && x <= '9')
        printf("%c is Digit.", x);
    else
        printf("%c is Special.", x);

    return 0;
}