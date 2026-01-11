#include <bits/stdc++.h>

using namespace std;

struct Cell
{
    int row, col;
};

// Directions: up, down, left, right
int dR[] = {-1, 1, 0, 0};
int dC[] = {0, 0, -1, 1};

bool isValid(int r, int c, int rows, int cols, const vector<vector<int>> &maze, vector<vector<bool>> &visited)
{
    return r >= 0 && r < rows && c >= 0 && c < cols && maze[r][c] != 1 && !visited[r][c];
}

void printPath(stack<Cell> &path)
{
    vector<Cell> result;
    while (!path.empty())
    {
        result.push_back(path.top());
        path.pop();
    }
    reverse(result.begin(), result.end());
    cout << "Path to treasure: ";
    for (const auto &cell : result)
    {
        cout << "(" << cell.row << "," << cell.col << "), ";
    }
    cout << endl;
}

void findPathToTreasure(const vector<vector<int>> &maze)
{
    int rows = maze.size(), cols = maze[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Cell>> parent(rows, vector<Cell>(cols, {-1, -1}));

    queue<Cell> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        Cell curr = q.front();
        q.pop();

        if (maze[curr.row][curr.col] == 999)
        {
            // Reconstruct path
            stack<Cell> path;
            while (!(curr.row == -1 && curr.col == -1))
            {
                path.push(curr);
                curr = parent[curr.row][curr.col];
            }
            printPath(path);
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int newRow = curr.row + dR[i];
            int newCol = curr.col + dC[i];
            if (isValid(newRow, newCol, rows, cols, maze, visited))
            {
                visited[newRow][newCol] = true;
                parent[newRow][newCol] = curr;
                q.push({newRow, newCol});
            }
        }
    }

    cout << "No path to treasure found." << endl;
}

int main()
{
    vector<vector<int>> maze = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 999, 0},
        {0, 0, 0, 1}};

    findPathToTreasure(maze);

    return 0;
}
