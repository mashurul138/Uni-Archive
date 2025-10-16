#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

void DPCoinChange(vector<int> &coins, int M)
{
    int c[M + 1], b[M + 1];
    c[0] = b[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        c[i] = INT_MAX;
        for (int j = 0; j < coins.size(); j++)
        {
            if (i >= coins[j] && 1 + c[i - coins[j]] < c[i])
            {
                c[i] = 1 + c[i - coins[j]];
                b[i] = coins[j];
            }
        }
    }

    cout << "Min number of coins " << c[M] << endl;
    int i = M;
    cout << "Choosen coins: ";
    while (i > 0)
    {
        cout << b[i] << " ";
        i -= b[i];
    }
}

int main()
{
    fastIO();
    vector<int> coins = {1, 2, 6};
    int change = 11;
    DPCoinChange(coins, change);
    return 0;
}