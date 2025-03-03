#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adjList[100];
int dis[100];
class comp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq;
    dis[src] = 0;
    pq.push({src, dis[src]});
    while (!pq.empty())
    {
        pair<int, int> par = pq.top();
        pq.pop();
        int parNode = par.first;
        int parDis = par.second;
        for (auto child : adjList[parNode])
        {
            int childNode = child.first;
            int childDis = child.second;

            if (parDis + childDis < dis[childNode])
            {
                dis[childNode] = parDis + childDis;
                pq.push({childNode,dis[childNode]});
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