#include <stdio.h>

int main()
{
    char strng[100];
    int Add = 0, l = 0;
    printf("Enter the string: ");
    fgets(strng, sizeof(strng), stdin);
    while (strng[l] != '\0')
    {
        if (strng[l] >= '0' && strng[l] <= '9')
        {
            Add += strng[l] - '0';
        }
        l++;
    }
    printf("%d\n", Add);
    return 0;
}