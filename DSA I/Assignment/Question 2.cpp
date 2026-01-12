#include <bits/stdc++.h>

using namespace std;

int n;
vector<vector<int>> cost;
int minCost = INT_MAX;

void dfs(int curCity, int visitedCnt, int curCost, vector<bool> &visited)
{
    if (visitedCnt == n)
    {
        if (cost[curCity][0] != 0)
            minCost = min(minCost, curCost + cost[curCity][0]);
        return;
    }

    if (curCost >= minCost)
        return;

    for (int nextCity = 0; nextCity < n; nextCity++)
    {
        if (!visited[nextCity] && cost[curCity][nextCity] != 0)
        {
            visited[nextCity] = true;
            dfs(nextCity, visitedCnt + 1, curCost + cost[curCity][nextCity], visited);
            visited[nextCity] = false;
        }
    }
}

int solve()
{
    vector<bool> visited(n, false);
    visited[0] = true;
    minCost = INT_MAX;

    dfs(0, 1, 0, visited);

    return (minCost == INT_MAX) ? -1 : minCost;
}

int main()
{
    cout << "Enter N: ";
    cin >> n;

    if (n < 2)
    {
        cout << "At least 2 locations are required" << endl;
        return 1;
    }

    cost.resize(n, vector<int>(n));

    cout << "Enter the cost matrix:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> cost[i][j];
    }

    cout << "Cost Matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << cost[i][j] << " ";
        cout << endl;
    }

    int result = solve();

    if (result == -1)
        cout << "No valid path exists!" << endl;
    else
        cout << "Minimum cost: " << result << endl;

    return 0;
}