#include <stdio.h>
#include <ctype.h>

struct Student
{
    char name[50];
    int age;
    float cgpa;
};

int main(void)
{
    struct Student students[4];

    for (size_t i = 0; i < 4; i++)
    {
        printf("Enter your name: ");
        gets(students[i].name);
        printf("Enter your age: ");
        scanf("%d", &students[i].age);
        printf("Enter your cgpa: ");
        scanf("%f", &students[i].cgpa);
        getchar();
    }

    for (size_t i = 0; i < 4; i++)
    {
        printstudentinfo(students[i]);
    }

    return 0;
}

void printstudentinfo(struct Student student)
{
    printf("Name = %s\n", student.name);
    printf("Age = %d\n", student.age);
    printf("Age = %f\n", student.cgpa);
}