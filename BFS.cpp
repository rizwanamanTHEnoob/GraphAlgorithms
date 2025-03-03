#include <bits/stdc++.h>
using namespace std;
void bfs(vector<int> adjList[], bool visited[], int nodes)
{
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
        int val = q.front();
        q.pop();
        cout << val << ' ';

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
    vector<int> adjList[nodes];
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    bool visited[nodes];
    memset(visited, false, sizeof(visited));
    bfs(adjList, visited, nodes);
}