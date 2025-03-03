#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
bool vis[100009];
vector<int> adjList[100009];
void dfs(int src, int &lastVis)
{
    vis[src] = true;
    lastVis = src;
    for (int child : adjList[src])
    {
        if (!vis[child])
        {
            dfs(child, lastVis);
        }
    }
}
void solve()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    vector<pair<int, int>> vp;
    int fin;
    int start;
    int lastVis;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (count > 0)
                vp.push_back({lastVis, i});
            lastVis = i;
            dfs(i, lastVis);
            count++;
        }
    }
    cout << vp.size() << endl;
    for (auto i : vp)
    {
        cout << i.first << ' ' << i.second << endl;
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}