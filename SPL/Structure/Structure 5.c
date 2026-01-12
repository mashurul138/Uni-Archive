#include <stdio.h>
#include <string.h>
struct student
{
    char name[40];
    char id[20];
    float cgpa;
};

int main()
{
    struct student s1;
    strcpy(s1.name, "Mashurul Haque Ibtid");
    strcpy(s1.id, "0112330547");
    s1.cgpa = 3.44;
    printf("Name: %s\n", s1.name);
    printf("ID: %s\n", s1.id);
    printf("CGPA: %.2f\n", s1.cgpa);
    return 0;
}