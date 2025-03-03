#include <bits/stdc++.h>
using namespace std;
bool vis[100];
vector<int> adj[105];
int parent[105];
bool hasCycle;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : adj[par])
        {
            if (vis[child] && parent[par] != child)
            {
                hasCycle = true;
            }
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
                parent[child] = par;
            }
        }
    }
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
        adj[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    hasCycle = false;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bfs(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << parent[i] << endl;
    }
    // if (hasCycle)
    //     cout << "Cycle Detected" << endl;
    // else
    //     cout << "No Cycle" << endl;
}