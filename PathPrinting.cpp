#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
bool visited[1000];
int parent[1000];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
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
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    adjList[nodes];
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
    int source, destination;
    cin >> source >> destination;
    bfs(source);
    vector<int> path;
    int node = destination;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    for (auto i : path)
    {
        cout << i << ' ';
    }
}