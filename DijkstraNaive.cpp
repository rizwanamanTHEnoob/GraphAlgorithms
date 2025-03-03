#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjList[100];
int dis[100];
void dijkstra(int src)
{
    queue<pair<int, int>> q;
    dis[src] = 0;
    q.push({src, dis[src]});
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        q.pop();
        int parNode = par.first;
        int parDis = par.second;
        for (auto child : adjList[parNode])
        {
            int childNode = child.first;
            int childDis = child.second;

            if (parDis + childDis < dis[childNode])
            {
                dis[childNode] = parDis + childDis;
                q.push({childNode,dis[childNode]});
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
        int node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        adjList[node1].push_back({node2, cost});
        adjList[node2].push_back({node1, cost});
    }
    for (int i = 0; i < n; i++)
        dis[i] = INT_MAX;
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
}