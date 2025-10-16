#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define up 1
#define diagonal 2

struct Bike
{
    string name;
    int wp, rp;
    int p = rp - wp;
};

void DPMaxProfit(vector<Bike> &bikes, int budget)
{
    int N = bikes.size();
    int p[bikes.size() + 1][budget + 1], b[bikes.size() + 1][budget + 1] = {{}};
    for (int i = 0; i <= bikes.size(); i++)
    {
        p[i][0] = 0;
    }
    for (int i = 0; i <= budget; i++)
    {
        p[0][i] = 0;
    }

    for (int i = 1; i <= bikes.size(); i++)
    {
        for (int j = 1; j <= budget; j++)
        {
            p[i][j] = p[i - 1][j];
            b[i][j] = up;
            if (j >= bikes[i - 1].wp && bikes[i - 1].p + p[i - 1][j - bikes[i - 1].wp] > p[i][j])
            {
                p[i][j] = bikes[i - 1].p + p[i - 1][j - bikes[i - 1].wp];
                b[i][j] = diagonal;
            }
        }
    }
    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= budget; j++)
        {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Max profit: " << p[bikes.size()][budget] << " lac " << endl;
    cout << "Selected motorcycles: " << endl;
    int n = N, t = budget;
    while (n > 0 && t > 0)
    {
        cout << n << " " << t << endl;
        if (p[n][t] == diagonal)
        {
            cout << bikes[n - 1].name << " " << bikes[n - 1].wp << " " << bikes[n - 1].p << endl;
            t -= bikes[n - 1].wp;
        }
        --n;
    }
}

int main()
{
    fastIO();
    vector<Bike> bikes = {
        {"R15", 3, 5},
        {"HD", 6, 14},
        {"RTR 160", 1, 2},
        {"CBR 150R", 4, 6}};

    int budget = 10;
    DPMaxProfit(bikes, budget);
    return 0;
}