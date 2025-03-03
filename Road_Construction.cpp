#include <bits/stdc++.h>
using namespace std;
int par[200099];
int groupSize[200099];
int maxComponents;
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
        maxComponents = max(maxComponents, groupSize[leader1]);
    }
    else
    {
        par[leader1] = leader2;
        groupSize[leader2] += groupSize[leader1];
        maxComponents = max(maxComponents, groupSize[leader2]);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    memset(par, -1, sizeof(par));
    for (int i = 0; i < 200099; i++)
    {
        groupSize[i] = 1;
    }
    int n, m;
    cin >> n >> m;
    maxComponents = INT_MIN;
    int components = n;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (find(u) != find(v))
        {
            components--;
            merge(u, v);
        }
        cout << components << ' ' << maxComponents << endl;
    }
}