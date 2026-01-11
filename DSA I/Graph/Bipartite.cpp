#include <bits/stdc++.h>

using namespace std;

bool isBipartite(vector<vector<int>> &graph)
{
    vector<int> color(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++)
    {
        if (color[i] == -1)
        {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int curNode = q.front();
                q.pop();
                for (int neighbor = 0; neighbor < graph.size(); neighbor++)
                {
                    if (graph[curNode][neighbor])
                    {
                        if (color[neighbor] == -1)
                        {
                            color[neighbor] = 1 - color[curNode];
                            q.push(neighbor);
                        }
                        else if (color[neighbor] == color[curNode])
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    vector<vector<int>> graph = {{0, 1, 0}, {1, 0, 1}, {0, 1, 0}};

    if (isBipartite(graph))
        cout << "The Graph is Bipartite." << endl;
    else
        cout << "The Graph is not Bipartite." << endl;

    return 0;
}