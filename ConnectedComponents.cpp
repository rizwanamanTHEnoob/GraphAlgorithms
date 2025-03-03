#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1005];
bool vis[1005];
void dfs(int source)
{
    vis[source] = true;
    for (int child : adjList[source])
    {
        if (!vis[child])
        {
            dfs(child);
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
    memset(vis,false,sizeof(vis));
    int count=0;
    for(int i=0;i<n;i++){
        if(vis[i]==false){
            count++;
            dfs(i);
        }
    }
    cout<<count<<endl;
}