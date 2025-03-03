#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    vector<int> adjList[nodes];
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a); // For undirected graph
    }
    for (int i = 0; i < nodes; i++)
    {
        cout << i << " -> ";
        for (auto j : adjList[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}
// When to use:
// When you want to iterate over all the edges of a node in O(degree) time.