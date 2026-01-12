#include <stdio.h>
void updateBalance(float bal[], int id, int type, float amount)
{
    if (type == 2 && amount > 0)
    {
        bal[id] += amount;
        printf("Updated Balance: %.2f\n", bal[id]);
    }
    else if (type == 1)
    {
        if (bal[id] < amount && amount > 0)
        {
            printf("Not sufficient Balance.\n");
            return;
        }
        else
        {
            bal[id] -= amount;
            printf("Updated Balance: %.2f\n", bal[id]);
        }
    }
}
int main()
{
    float bal[5];
    int id, type;
    float amount;
    for (int i = 0; i < 5; i++)
    {
        printf("Enter Current Balance 0f %d user: ", i + 1);
        scanf("%f", &bal[i]);
    }
    printf("Enter ID: ");
    scanf("%d", &id);
    printf("Enter Transaction Type: ");
    scanf("%d", &type);
    printf("Enter Amount: ");
    scanf("%f", &amount);
    updateBalance(bal, id, type, amount);
    return 0;
}
