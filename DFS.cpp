#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1005];
bool visited[1005];
void DFS(int source)
{
    cout << source << ' ';
    visited[source] = true;
    for (int i : adjList[source])
    {
        if (!visited[i])
        {
            DFS(i);
        }
    }
}
int main()
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
    memset(visited, false, sizeof(visited));
    DFS(0);
}