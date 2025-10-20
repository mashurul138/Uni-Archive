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
        int x = find(a);
        int y = find(b);

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

int main()
{
    int n;
    cin >> n;
    // vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> edges = {{0, 1}, {3, 5}, {2, 0}, {5, 4}, {4, 3}};

    int s, d;
    cin >> s >> d;
    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
        ds.makeSet(i);

    for (int i = 0; i < edges.size(); i++)
        ds.Union(edges[i][0], edges[i][1]);
    
        if (ds.find(s) == ds.find(d))
        cout << "True" << endl;
    else
        cout << "False" << endl;
}