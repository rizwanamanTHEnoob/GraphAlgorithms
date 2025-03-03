#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<pair<ll, ll>> adjList[100009];
ll dis[100009];
ll parent[100009];
class comp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, comp> pq;
    dis[src] = 0;
    pq.push({src, dis[src]});
    while (!pq.empty())
    {
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll parNode = par.first;
        ll parDis = par.second;
        for (auto child : adjList[parNode])
        {
            ll childNode = child.first;
            ll childDis = child.second;

            if (parDis + childDis < dis[childNode])
            {
                dis[childNode] = parDis + childDis;
                pq.push({childNode, dis[childNode]});
                parent[childNode] = parNode;
            }
        }
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll node1, node2, cost;
        cin >> node1 >> node2 >> cost;
        adjList[node1].push_back({node2, cost});
        adjList[node2].push_back({node1, cost});
    }
    for (ll i = 1; i <= n; i++)
    {
        dis[i] = LLONG_MAX;
        parent[i] = -1;
    }
    dijkstra(1);
    if (dis[n] != LLONG_MAX)
    {
        vector<int> take;
        ll x = n;
        while (x != -1)
        {
            take.push_back(x);
            x = parent[x];
        }
        reverse(take.begin(), take.end());
        for (auto i : take)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}