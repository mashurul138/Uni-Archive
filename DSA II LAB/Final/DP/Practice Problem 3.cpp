#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define up 1
#define diagonal 2

struct Project
{
    int profit, duration;
};

void DPMaxProfit(vector<Project> projects, int n, int d)
{
    int p[n + 1][d + 1], b[n + 1][d + 1];
    for (int i = 0; i <= n; i++)
    {
        p[i][0] = 0;
    }
    for (int i = 0; i <= d; i++)
    {
        p[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            p[i][j] = p[i - 1][j];
            b[i][j] = up;
            if (j >= projects[i - 1].duration && projects[i - 1].profit + p[i - 1][j - projects[i - 1].duration] > p[i][j])
            {
                p[i][j] = projects[i - 1].profit + p[i - 1][j - projects[i - 1].duration];
                b[i][j] = diagonal;
            }
        }
    }

    cout << "Max Profit : " << p[n][d] << endl;
    int i = n, j = d;
    while (i > 0 && j > 0)
    {
        if (b[i][j] == diagonal)
        {
            cout << projects[i - 1].duration << " " << projects[i - 1].profit << endl;
            j -= projects[i - 1].duration;
        }
        --i;
    }
}

int main()
{
    fastIO();
    int n, d;
    cin >> n >> d;
    vector<Project> projects = {
        {200, 3},
        {150, 2},
        {100, 1},
        {50, 2},
        {300, 5}};
    DPMaxProfit(projects, n, d);
    return 0;
}