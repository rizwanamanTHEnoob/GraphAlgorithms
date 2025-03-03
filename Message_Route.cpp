#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1e9 + 7;
bool visited[100010];
vector<int> adjList[100010];
int parent[100010];
void BFS(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    parent[source] = -1;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : adjList[par])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = par;
            }
        }
    }
}
void solve()
{
    int nodes, edges;
    cin >> nodes >> edges;
    adjList[nodes + 1];
    visited[nodes + 1];

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    int source = 1;
    int destinatio = nodes;
    BFS(source);
    vector<int> path;
    int node = destinatio;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    if (!visited[destinatio])
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        cout << path.size() << endl;
        reverse(path.begin(),path.end());
        for (auto i : path)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}