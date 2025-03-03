#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1000];
bool visited[1000];
int level[1000];
void bfs(int source)
{
    queue<int> q;
    q.push(source);
    visited[source] = true;
    level[source] = 0;
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
                level[i] = level[val] + 1;
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
    memset(level, -1, sizeof(level));
    int source, destination;
    cin >> source >> destination;
    bfs(source);
    cout<<level[destination];
}