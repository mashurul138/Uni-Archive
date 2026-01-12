#include <stdio.h>
#include <conio.h>

struct player
{
    char name[40];
    char country[20];
    int runs[3];
    int wickets[3];
    int points[3];
} p1, p2;

void input(struct player *x)
{
    printf("Enter Player Name: ");
    fflush(stdin);
    gets(x->name);
    printf("Enter Player Country: ");
    fflush(stdin);
    gets(x->country);

    for (int i = 0; i < 3; i++)
    {
        printf("%d Match Run: ", i + 1);
        scanf("%d", &x->runs[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        printf("%d Match Wicket: ", i + 1);
        scanf("%d", &x->wickets[i]);
    }
}

void points(struct player *x)
{
    for (int i = 0; i < 3; i++)
    {
        x->points[i] = x->wickets[i] * 12;
        if (x->runs[i] > 75)
        {
            x->points[i] += 20;
        }
        else if (x->runs[i] > 50)
        {
            x->points[i] += 15;
        }
        else if (x->runs[i] > 25)
        {
            x->points[i] += 10;
        }
        else if (x->runs[i] > 0)
        {
            x->points[i] += 5;
        }
    }
}

void display(struct player *x, struct player *y)
{
    for (int i = 0; i < 3; i++)
    {
        printf("Match %d:\n", i + 1);
        printf("%s Points: %d\n", x->name, x->points[i]);
        printf("%s Points: %d\n\n\n", y->name, y->points[i]);
    }
}

int main()
{
    input(&p1);
    input(&p2);
    points(&p1);
    points(&p2);
    display(&p1, &p2);
    return 0;
}
