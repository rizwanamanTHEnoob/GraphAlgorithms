#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
int dis[100];
int n, e;
vector<Edge> edgeList;
void bellmanFord()
{
    bool cycle = false;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto edge : edgeList)
        {
            int a, b, c;
            a = edge.a;
            b = edge.b;
            c = edge.c;
            if (dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }
    for (auto edge : edgeList)
    {
        int a, b, c;
        a = edge.a;
        b = edge.b;
        c = edge.c;
        if (dis[a] != INT_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
        }
    }
    if (cycle)
    {
        cout << "Negative weighted cycle detected" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << i << " -> " << dis[i] << endl;
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edgeList.push_back(Edge(a, b, c));
    }
    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    bellmanFord();
}