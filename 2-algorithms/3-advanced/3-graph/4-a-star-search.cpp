// (Pathfinding - Heuristic)*
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

struct Node
{
    int x, y;
    int g, h;
    Node *parent;

    Node(int x, int y, int g, int h, Node *parent = nullptr)
        : x(x), y(y), g(g), h(h), parent(parent) {}

    int f() const { return g + h; }
};

struct Compare
{
    bool operator()(const Node *a, const Node *b)
    {
        return a->f() > b->f();
    }
};

vector<pair<int, int>> aStar(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> end)
{
    int rows = grid.size(), cols = grid[0].size();
    priority_queue<Node *, vector<Node *>, Compare> pq;
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    vector<vector<Node *>> nodes(rows, vector<Node *>(cols, nullptr));

    auto heuristic = [](int x1, int y1, int x2, int y2)
    {
        return abs(x1 - x2) + abs(y1 - y2);
    };

    Node *startNode = new Node(start.first, start.second, 0, heuristic(start.first, start.second, end.first, end.second));
    pq.push(startNode);
    nodes[start.first][start.second] = startNode;

    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!pq.empty())
    {
        Node *current = pq.top();
        pq.pop();
        int x = current->x, y = current->y;

        if (visited[x][y])
            continue;
        visited[x][y] = true;

        if (x == end.first && y == end.second)
        {
            vector<pair<int, int>> path;
            while (current)
            {
                path.emplace_back(current->x, current->y);
                current = current->parent;
            }
            reverse(path.begin(), path.end());
            return path;
        }

        for (auto [dx, dy] : directions)
        {
            int nx = x + dx, ny = y + dy;
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 0 && !visited[nx][ny])
            {
                int newG = current->g + 1;
                if (!nodes[nx][ny] || newG < nodes[nx][ny]->g)
                {
                    Node *neighbor = new Node(nx, ny, newG, heuristic(nx, ny, end.first, end.second), current);
                    pq.push(neighbor);
                    nodes[nx][ny] = neighbor;
                }
            }
        }
    }
    return {};
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

void testAStar()
{
    {
        vector<vector<int>> grid = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 2};

        vector<pair<int, int>> path = aStar(grid, start, end);
        vector<pair<int, int>> expected = {{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}};
        assert(!path.empty());
        assert(path.front() == start);
        assert(path.back() == end);
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 3};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(!path.empty());
        assert(path.front() == start);
        assert(path.back() == end);
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 3};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(path.empty());
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        pair<int, int> start = {1, 1};
        pair<int, int> end = {1, 1};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(path.size() == 1);
        assert(path.front() == start);
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 3};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(!path.empty());
        assert(path.front() == start);
        assert(path.back() == end);
    }

    cout << "All test cases passed!" << endl;
}

int main()
{
    testAStar();
    return 0;
}
