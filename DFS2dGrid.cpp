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
void DFS(int x, int y)
{
    cout << x << ' ' << y << endl;
    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isValid(newX, newY) && !visited[newX][newY])
        {
            DFS(newX, newY);
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
    DFS(x, y);
}