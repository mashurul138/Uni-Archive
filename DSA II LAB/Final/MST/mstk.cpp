#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
    int n;
    vector<int> p, rank;

public:
    DisjointSet(int n) : n(n)
    {
        p = rank = vector<int>(n);
    }
    void makeSet(int x)
    {
        p[x] = x;
        rank[x] = 0;
    }
    int find(int x)
    {
        if (x != p[x])
            p[x] = find(p[x]);
        return p[x];
    }
    void Union(int a, int b)
    {
        int x = p[a];
        int y = p[b];
        if (x == y)
            return;
        if (rank[x] > rank[y])
            p[y] = x;
        else
        {
            p[x] = y;
            if (rank[x] == rank[y])
                rank[y]++;
        }
    }
};

class Graph
{
    int n;
    vector<vector<int>> edges;

public:
    Graph(int n) : n(n) {}
    void addEdge(int u, int v, int w)
    {
        edges.push_back({w, u, v});
    }

    void Kruskal()
    {
        vector<vector<int>> t;
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            ds.makeSet(i);
        }
        sort(edges.begin(), edges.end());

        for (int i = 0; i < edges.size(); i++)
        {
            int w = edges[i][0];
            int u = edges[i][1];
            int v = edges[i][2];

            if (ds.find(u) != ds.find(v))
            {
                t.push_back({u, v, w});
                ds.Union(u, v);
            }
            else
            {
                cout << "cycle detected" << endl;
            }
        }

        cout << "Choosen edges : " << endl;
        int c = 0;
        for (int i = 0; i < t.size(); i++)
        {
            int u = t[i][0];
            int v = t[i][1];
            int w = t[i][2];
            c += w;
            printf("(%d, %d, %d)\n", u, v, w);
        }
        cout << "Cost: " << c;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w);
    }
    g.Kruskal();
    return 0;
}