#include <bits/stdc++.h>
using namespace std;
int par[1005];
int groupSize[1005];
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        par[i] = -1;
        groupSize[i] = 1;
    }
    vector<pair<int, int>> vp, newRoad;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        if (find(u) == find(v))
        {
            cnt++;
            vp.push_back({u, v});
        }
        else
            merge(u, v);
    }
    for (int i = 2; i <= n; i++)
    {
        int l1 = find(1);
        int l2 = find(i);
        cout<<l1<<' '<<l2<<endl;
        cout<<par[1]<<' '<<par[i]<<endl;
        if (l1 != l2)
        {
            newRoad.push_back({1, i});
            merge(1, i);
        }

    }
    // cout << cnt << endl;
    // for (int i = 0; i < cnt; i++)
    // {
    //     cout << vp[i].first << ' ' << vp[i].second;
    //     cout << ' ' << newRoad[i].first << ' ' << newRoad[i].second << endl;
    // }
}