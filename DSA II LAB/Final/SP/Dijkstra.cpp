#include <bits/stdc++.h>
using namespace std;

#define fastIO()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

class Graph
{
    int n;
    bool directed;
    vector<vector<int>> w;
    vector<int> d, p, q;

public:
    Graph(int n, bool dir) : n(n), directed(dir)
    {
        w = vector<vector<int>>(n, vector<int>(n, 0));
    }

    void addEdge(int u, int v, int weight)
    {
        w[u][v] = weight;
        if (!directed)
            w[v][u] = weight;
    }

    bool isEdge(int u, int v)
    {
        return !(w[u][v] == 0);
    }

    int extractMin()
    {
        int m = INT_MAX, idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (q[i] == 1 && d[i] < m)
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
                if (isEdge(u, v) && d[u] + w[u][v] < d[v])
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
        printf("%d --> ", d);
    }

    void findPath(int u, int v)
    {
        dijkstra(u);
        printf("path from %d to %d: ", u, v);
        printPath(v);
        printf("\ndistance from %d to %d is %d\n\n", u, v, d[v]);
    }
};

int main()
{
    fastIO();

    Graph g(5, true);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 4, 2);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 1, 1);
    g.addEdge(3, 4, 1);
    int src = 0;
    for (int i = 0; i < 5; i++)
    {
        g.findPath(src,i);
    }
    
    // g.findPath(0, 4);
    return 0;
}