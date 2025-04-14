
---

### 📄 `main.cpp`

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <cmath>

using namespace std;

struct Cell {
    int x, y;
    int g; // cost from start
    int f; // total estimated cost
    bool operator>(const Cell& other) const {
        return f > other.f;
    }
};

const int ROWS = 10;
const int COLS = 10;

char grid[ROWS][COLS] = {
    {'S','.','.','.','.','~','.','.','^','.'},
    {'#','#','#','.','.','~','#','.','^','.'},
    {'.','.','.','#','.','.','#','.','.','.'},
    {'.','~','~','#','.','.','.','.','.','.'},
    {'.','.','.','.','.','#','#','#','#','.'},
    {'^','^','.','.','.','.','.','.','~','.'},
    {'#','.','.','.','.','#','~','~','~','.'},
    {'.','.','#','#','.','.','.','.','.','.'},
    {'.','.','.','.','.','^','^','^','^','G'},
    {'.','#','#','#','#','#','#','.','.','.'}
};

int terrainCost(char tile) {
    switch (tile) {
        case '.': return 1;
        case '~': return 3;
        case '^': return 5;
        case 'S': case 'G': return 0;
        default: return INT_MAX; // walls
    }
}

int heuristic(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

bool isValid(int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && grid[x][y] != '#';
}

int main() {
    pair<int, int> start, goal;
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 'S') start = {i, j};
            if (grid[i][j] == 'G') goal = {i, j};
        }

    priority_queue<Cell, vector<Cell>, greater<Cell>> open;
    vector<vector<int>> cost(ROWS, vector<int>(COLS, INT_MAX));
    vector<vector<pair<int,int>>> parent(ROWS, vector<pair<int,int>>(COLS, {-1,-1}));

    cost[start.first][start.second] = 0;
    open.push({start.first, start.second, 0, heuristic(start.first, start.second, goal.first, goal.second)});

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!open.empty()) {
        Cell curr = open.top(); open.pop();

        cout << "(" << curr.x << "," << curr.y << ")" << endl; // Print visited

        if (make_pair(curr.x, curr.y) == goal) {
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isValid(nx, ny)) {
                int newCost = cost[curr.x][curr.y] + terrainCost(grid[nx][ny]);
                if (newCost < cost[nx][ny]) {
                    cost[nx][ny] = newCost;
                    int f = newCost + heuristic(nx, ny, goal.first, goal.second);
                    open.push({nx, ny, newCost, f});
                    parent[nx][ny] = {curr.x, curr.y};
                }
            }
        }
    }

    cout << "\nTotal Path Cost: " << cost[goal.first][goal.second] << endl;
    return 0;
}
