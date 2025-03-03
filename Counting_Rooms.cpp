#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
int n, m;
char grid[1005][1005];
bool vis[1005][1005];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool valid(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;
    return true;
}
void dfs(int x, int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        int newi = x + dx[i];
        int newj = y + dy[i];
        if (!vis[newi][newj] && valid(newi, newj) && grid[newi][newj] == '.')
        {
            dfs(newi, newj);
        }
    }
}
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    memset(vis, false, sizeof(vis));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == '.')
            {
                count++;
                dfs(i, j);
            }
        }
    }
    cout << count << endl;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}