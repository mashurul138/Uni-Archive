#include <bits/stdc++.h>

using namespace std;

void createGraph(vector<vector<int>> &graph, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}

void bfs(vector<vector<int>> &graph, int startNode)
{
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    q.push(startNode);
    visited[startNode] = true;

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int curNote = q.front();
        q.pop();
        cout << curNote << " ";
        for (auto neighbor : graph[curNote])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

void dfs(vector<vector<int>> &graph, int startNode)
{
    stack<int> s;
    vector<bool> visited(graph.size(), false);

    s.push(startNode);

    cout << "DFS Traversal: ";
    while (!s.empty())
    {
        int curNode = s.top();
        s.pop();

        if (!visited[curNode])
        {
            cout << curNode << " ";
            visited[curNode] = true;

            for (auto neighbor : graph[curNode])
            {
                if (!visited[neighbor])
                {
                    // s.push(neighbor);
                    dfs(graph, neighbor);
                }
            }
        }
    }
    cout << endl;
}

void dfsUtil(vector<vector<int>> &graph, int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (auto neighbor : graph[node])
    {
        if (!visited[neighbor])
            dfsUtil(graph, neighbor, visited);
    }
}

void DFS(vector<vector<int>> &graph, int startNode)
{
    vector<bool> visited(graph.size(),false);
    cout << "DFS Traversal: ";
    dfsUtil(graph,startNode,visited);
    cout << endl;
}

void displayGraph(vector<vector<int>> &graph)
{
    cout << "Adjacency List: " << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        if (!graph[i].empty())
        {
            cout << i << ": ";
            for (auto neighbor : graph[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int v = 8;
    vector<vector<int>> graph(v);
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 6}, {3, 7}};

    createGraph(graph, edges);

    for (auto branch : graph)
        sort(branch.begin(), branch.end());
    displayGraph(graph);

    bfs(graph, 0);
    DFS(graph, 0);
}