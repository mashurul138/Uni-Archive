#include <stdio.h>
#include <string.h>

struct card
{
    char name[60];
    int stage;
    int hp;
}pok[100];

int ends_with (char *input, char letter)
{
    if (*(input+strlen(input)-1) == letter)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        gets(pok[i].name);
        scanf("%d %d", &pok[i].stage, &pok[i].hp);
    }

    int arr[100];
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 50;
        arr[i] += pok[i].hp;
        if (pok[i].stage == 1)
        {
            arr[i] += 30;
        }
        else if (pok[i].stage == 2)
        {
            arr[i] += 70;
        }
        if (ends_with(pok[i].name,'X'))
        {
            arr[i] += 200;
        }
        total += arr[i];
    }
    printf("\n%d", total);
    return 0;
}
