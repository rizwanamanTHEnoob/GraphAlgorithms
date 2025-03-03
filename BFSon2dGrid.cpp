#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visited[105][105];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n, m;
bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}
void BFS(int x, int y)
{
    queue<pair<int, int>> q;    
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        cout << p.first << ' ' << p.second << endl;
        for (int i = 0; i < 4; i++)
        {
            int newX = p.first + dx[i];
            int newY = p.second + dy[i];
            if (isValid(newX, newY) && !visited[newX][newY])
            {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    int x, y;
    cin >> x >> y;
    memset(visited, false, sizeof(visited));
    BFS(x, y);
}