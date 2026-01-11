#include <bits/stdc++.h>

using namespace std;

bool isSafe(int x, int y, vector<vector<int>> &maze, vector<vector<bool>> &visited)
{
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze.size() && maze[x][y] == 1 && !visited[x][y]);
}

bool solveUtil(int x, int y, vector<vector<int>> &maze, vector<pair<int, int>> &path, vector<vector<bool>> &visited)
{
    if (x == maze.size() - 1 && y == maze.size() - 1)
    {
        path.push_back({x, y});
        return true;
    }

    if (isSafe(x, y, maze, visited))
    {
        visited[x][y] = true;
        path.push_back({x, y});

        vector<int> rd = {0, 0, -1, 1};
        vector<int> cd = {-1, 1, 0, 0};
        for (int i = 0; i < maze.size(); i++)
        {
            int newR = x + rd[i];
            int newC = y + cd[i];
            if (solveUtil(newR, newC, maze, path, visited))
                return true;
        }
        path.pop_back();
        visited[x][y] = false;
    }
    return false;
}

void solve(vector<vector<int>> &maze)
{
    vector<pair<int, int>> path;
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze.size(), false));

    if (solveUtil(0, 0, maze, path, visited))
    {
        cout << "path from (0,0) to (3,3): ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << "(" << path[i].first << ", " << path[i].second << ")";
            if (i != path.size() - 1)
                cout << ", ";
        }
        cout << endl;
    }
    else
        cout << "No path exist." << endl;
}

int main()
{
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 1, 0},
                                {0, 1, 0, 0},
                                {0, 1, 1, 1}};
    solve(maze);
    return 0;
}