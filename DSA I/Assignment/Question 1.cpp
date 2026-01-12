#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> graph;
int n;

int bfs(int start, int end)
{
    if (start == end)
        return 0;

    vector<bool> visited(n, false);
    vector<int> distance(n, -1);
    queue<int> q;

    q.push(start);
    visited[start] = true;
    distance[start] = 0;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);

                if (neighbor == end)
                    return distance[neighbor];
            }
        }
    }
    return -1;
}

void add_edge()
{
    int u, v;
    cout << "Enter edge (u v): ";
    cin >> u >> v;

    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        cout << "Error: Vertices must be between 0 and " << (n - 1) << endl;
        return;
    }

    graph[u].push_back(v);
    graph[v].push_back(u);
}

void find_shortest_path()
{
    int u, v;
    cout << "Enter source and destination (u v): ";
    cin >> u >> v;

    if (u < 0 || u >= n || v < 0 || v >= n)
    {
        cout << "Error: Vertices must be between 0 and " << (n - 1) << endl;
        return;
    }

    int result = bfs(u, v);

    if (result == -1)
        cout << "No path exists between " << "(" << u << ", " << v << ")." << endl;
    else
        cout << "Minimum number of edges between " << "(" << u << ", " << v << "): " << result << endl;
}

void display()
{
    cout << "--- Current Graph Structure ---" << endl;
    bool has_edges = false;

    for (int i = 0; i < n; i++)
    {
        if (!graph[i].empty())
        {
            cout << "Vertex " << i << ": ";
            for (int j = 0; j < graph[i].size(); j++)
                cout << graph[i][j] << " ";
            cout << endl;
            has_edges = true;
        }
    }

    if (!has_edges)
        cout << "Graph is empty" << endl;
    cout << endl;
}

void menu()
{
    cout << "1. Add edge" << endl;
    cout << "2. Find shortest path" << endl;
    cout << "3. Display graph" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: Number of vertices must be positive!" << endl;
        return 1;
    }

    graph.resize(n);

    int choice;
    while (true)
    {
        menu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            add_edge();
            break;

        case 2:
            find_shortest_path();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
            break;
        }
    }
    return 0;
}