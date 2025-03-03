#include <bits/stdc++.h>
using namespace std;
bool vis[100];
vector<int> adj[105];
bool pathvis[100];
bool hasCycle;
void dfs(int src)
{
    vis[src] = true;
    pathvis[src] = true;
    for (int child : adj[src])
    {
        if (pathvis[child] && vis[child])
        {
            hasCycle = true;
        }
        if (!vis[child])
        {
            dfs(child);
        }
    }
    pathvis[src] = false;
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    memset(vis, false, sizeof(vis));
    memset(pathvis, false, sizeof(pathvis));
    hasCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    if (hasCycle)
        cout << "Cycle Detected" << endl;
    else
        cout << "No Cycle" << endl;
}