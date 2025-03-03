#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll v, e;
const ll s = 1e5 + 100;
vector<pair<ll, ll>> adjList[s];
ll dis[s];
void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dis[src] = 0;
    pq.push({dis[src], src});
    while (!pq.empty())
    {
        pair<ll, ll> par = pq.top();
        pq.pop();
        ll parNode = par.second;
        ll parDis = par.first;
        if (parDis > dis[parNode])
            continue;
        for (auto child : adjList[parNode])
        {
            ll childNode = child.first;
            ll childDis = child.second;

            if (parDis + childDis < dis[childNode])
            {
                dis[childNode] = parDis + childDis;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> v >> e;
    for (int i = 1; i <= v; i++)
    {
        dis[i] = LLONG_MAX;
    }
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjList[a].push_back({b, c});
    }
    dijkstra(1LL);
    for (int i = 1; i <= v; i++)
    {
        cout << dis[i] << ' ';
    }
}