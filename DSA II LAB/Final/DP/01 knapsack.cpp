#include <bits/stdc++.h>
using namespace std;

#define up 1
#define diagonal 2

struct Item
{
    string name;
    int weight, value;
};

void knapsack(vector<Item> &items, int n, int W)
{
    int dp[n + 1][W + 1];
    int bt[n + 1][W + 1];
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= W; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            dp[i][j] = dp[i - 1][j];
            bt[i][j] = up;
            if (j >= items[i - 1].weight && items[i - 1].value + dp[i - 1][j - items[i - 1].weight] > dp[i][j])
            {
                dp[i][j] = items[i - 1].value + dp[i - 1][j - items[i - 1].weight];
                bt[i][j] = diagonal;
            }
        }
    }
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 0; j <= W; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << "Max Profit " << dp[n][W] << endl;
    int i = n, j = W;
    cout << "Selected Items: " << endl;
    while (i > 0 && j > 0)
    {
        if (bt[i][j] == diagonal)
        {
            cout << items[i - 1].name << " " << items[i - 1].weight << "kg " << items[i - 1].value << endl;
            j -= items[i - 1].weight;
        }
        --i;
    }
}

int main()
{
    int n, W;
    cin >> n >> W;
    vector<Item> items = {{"Rice", 2, 12},
                          {"Sugar", 1, 10},
                          {"Salt", 3, 20},
                          {"Lentil", 2, 15}};
    knapsack(items, n, W);
}