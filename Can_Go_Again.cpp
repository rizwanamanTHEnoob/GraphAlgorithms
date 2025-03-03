#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    long long a, b, c;
    Edge(long long a, long long b, long long c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};
long long dis[1009];
int n, e;
vector<Edge> edgeList;
bool cycle;
void bellmanFord()
{
    bool change=false;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto edge : edgeList)
        {
            long long a, b, c;
            a = edge.a;
            b = edge.b;
            c = edge.c;
            if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
                change=true;
            }
        }
        if(!change) break;
    }
    for (auto edge : edgeList)
    {
        long long a, b, c;
        a = edge.a;
        b = edge.b;
        c = edge.c;
        if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
        {
            cycle = true;
            break;
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
    for (int i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
    }
    long long src;
    cin >> src;
    dis[src] = 0;
    cycle = false;
    bellmanFord();
    if (cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int d;
        cin >> d;
        if (dis[d] != LLONG_MAX)
        {
            cout << dis[d] << endl;
        }
        if (dis[d] == LLONG_MAX)
        {
            cout << "Not Possible" << endl;
        }
    }
}