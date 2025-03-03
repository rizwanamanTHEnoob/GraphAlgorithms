#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
bool visited[1000];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        for (auto i : adjList[val])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
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
    memset(visited, false, sizeof(visited[0]) * nodes);
    int source, destination;
    cin >> source >> destination;
    bfs(source);
    if (visited[destination])
    {
        cout << "Path exists";
    }
    else
    {
        cout << "Path does not exist";
    }
}