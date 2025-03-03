#include <bits/stdc++.h>
using namespace std;
int par[100009];
int groupSize[100009];
int find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
void merge(int u, int v)
{
    int leader1 = find(u);
    int leader2 = find(v);

    if (groupSize[leader1] >= groupSize[leader2])
    {
        par[leader2] = leader1;
        groupSize[leader1] += groupSize[leader2];
    }
    else
    {
        par[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
    }
}
int main()
{
    memset(par, -1, sizeof(par));
    memset(groupSize, 1, sizeof(groupSize));
    int n, e;
    cin >> n >> e;
    bool cycle = false;
    int cnt = 0;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v))
        {
            cnt++;
        }
        else
            merge(u, v);
    }
    cout << cnt << endl;

    return 0;
}