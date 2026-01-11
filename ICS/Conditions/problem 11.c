// Program that will take the final score of a student in a particular subject as input and find his/her grade.
#include <stdio.h>

int main()
{
    float x;
    printf("Enter Final Number: ");
    scanf("%f", &x);

    if (x >= 90 && x <= 100)
        printf("Grade A.");
    else if (x >= 86)
        printf("Grade A-.");
    else if (x >= 82)
        printf("Grade B+.");
    else if (x >= 78)
        printf("Grade B.");
    else if (x >= 74)
        printf("Grade B-.");
    else if (x >= 70)
        printf("Grade C+.");
    else if (x >= 66)
        printf("Grade C.");
    else if (x >= 62)
        printf("Grade C-.");
    else if (x >= 58)
        printf("Grade D+.");
    else if (x >= 55)
        printf("Grade D.");
    else
        printf("Grade F.");

    return 0;
}