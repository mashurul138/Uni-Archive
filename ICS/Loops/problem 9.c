// Write a program (WAP) that will find the grade of N students. For each student, it will take
// the marks of his/her the attendance (on 5 marks), assignment (on 10 marks), class test
//(on 15 marks), midterm (on 50 marks), term final (on 100 marks). Then based on the
// tables shown below, the program will output his grade.

#include <stdio.h>
int main()
{
    int n, i;
    float A, hw, ct, mt, ft, total, percentage;
    printf("Number of students: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        printf("Marks on attendance assignment CT Midterm Final: ");
        scanf("%f%f%f%f%f", &A, &hw, &ct, &mt, &ft);
        total = (A + hw + ct + mt + ft);
        percentage = (total / 180) * 100;
        if (percentage >= 90)
            printf("Student %d : A\n", i);
        else if (percentage >= 86)
            printf("Student %d : A-\n", i);
        else if (percentage >= 82)
            printf("Student %d : B+\n", i);
        else if (percentage >= 78)
            printf("Student %d : B\n", i);
        else if (percentage >= 74)
            printf("Student %d : B-\n", i);
        else if (percentage >= 70)
            printf("Student %d : C+\n", i);
        else if (percentage >= 66)
            printf("Student %d : C\n", i);
        else if (percentage >= 62)
            printf("Student %d : C-\n", i);
        else if (percentage >= 58)
            printf("Student %d : D+\n", i);
        else if (percentage >= 55)
            printf("Student %d : D\n", i);
        else
            printf("Student %d : F\n", i);
    }
    return 0;
}
