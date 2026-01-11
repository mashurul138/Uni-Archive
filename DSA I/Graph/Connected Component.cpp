#include <bits/stdc++.h>

using namespace std;

void createGraph(vector<vector<int>> &graph, vector<vector<int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

void dfs(int startNode, vector<vector<int>> &graph, vector<bool> &visited, vector<int> &component)
{
    visited[startNode] = true;
    component.push_back(startNode);

    for (int neighbor : graph[startNode])
    {
        if (!visited[neighbor])
            dfs(neighbor, graph, visited, component);
    }
}

void display(vector<vector<int>> &graph)
{
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!graph[i].empty())
        {
            cout << i << ": ";
            for (int neighbor : graph[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int v = 5;
    vector<vector<int>> graph(v);
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {3, 4}};
    vector<bool> visited(v, false);
    vector<vector<int>> res;

    createGraph(graph, edges);
    display(graph);

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            vector<int> component;
            dfs(i, graph, visited, component);
            res.push_back(component);
        }
    }

    cout << "Connected Component: " << res.size() << endl;
    for (auto comp : res)
    {
        for (auto node : comp)
            cout << node << " ";
        cout << endl;
    }

    return 0;
}