/*Given a 2D grid of size n*n, where each cell represents the cost to traverse through that cell,
 the task is to find the minimum cost to move from the top left cell to the bottom right cell.
*/
#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class MinCost
{
    int n;
    vector<vector<int>> w;
    vector<int> d, p, q;

public:
    MinCost(vector<vector<int>> w) : w(w)
    {
        n = w.size();
    }

    int extractMin()
    {
        int m = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (d[i] < m)
            {
                m = d[i];
                idx = i;
            }
        }
        return idx;
    }

    void dijkstra(int src)
    {
        d = vector<int>(n, INT_MAX);
        p = vector<int>(n, -1);
        q = vector<int>(n, 1);

        d[src] = 0;
        for (int i = 1; i <= n; i++)
        {
            int u = extractMin();
            q[u] = 0;
            for (int v = 0; v < n; v++)
            {
                if (d[u] + w[u][v] < d[v])
                {
                    d[v] = d[u] + w[u][v];
                    p[v] = u;
                }
            }
        }
    }

    void printPath(int d)
    {
        if (d == -1)
            return;
        printPath(p[d]);
        printf("%d -->", d);
    }

    void findPath(int u, int v)
    {
        dijkstra(u);
        printf("path: ");
        printPath(v);
        printf("distance: %d", d[v]);
    }
};

int main()
{
    fastIO();
    vector<vector<int>> w = {{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    MinCost m(w);
    m.findPath(0, w.size() - 1);
    return 0;
}