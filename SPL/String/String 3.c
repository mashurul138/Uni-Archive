#include <stdio.h>

int main()
{
    char sntnc[100];
    int l = 0, flag = 0;
    printf("Enter the String: ");
    fgets(sntnc, sizeof(sntnc), stdin);
    while (sntnc[l] != '\0')
    {
        if (sntnc[l] == 'a' || sntnc[l] == 'A' || sntnc[l] == 'e' || sntnc[l] == 'E' || sntnc[l] == 'i' || sntnc[l] == 'I' || sntnc[l] == 'o' || sntnc[l] == 'O' || sntnc[l] == 'u' || sntnc[l] == 'U')
        {
            flag++;
        }
        l++;
    }
    printf("%d\n", flag);
    return 0;
}