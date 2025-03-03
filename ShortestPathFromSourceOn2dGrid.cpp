#include <bits/stdc++.h>
using namespace std;
char grid[105][105];
bool visited[105][105];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int dist[105][105];
int n, m;
bool isValid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
    {
        return false;
    }
    return true;
}
void shortestDistance(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    dist[x][y] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int childX = par.first + dx[i];
            int childY = par.second + dy[i];
            if (isValid(childX, childY) && !visited[childX][childY])
            {
                q.push({childX, childY});
                visited[childX][childY] = true;
                dist[childX][childY] = dist[par.first][par.second] + 1;
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
    memset(dist, -1, sizeof(dist));
    int destinationX, destinationY;
    shortestDistance(x, y);
    cout << dist[destinationX][destinationY];
}