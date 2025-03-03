#include <bits/stdc++.h>
using namespace std;
int main(){
    int nodes, edges;
    cin >> nodes >> edges;
    vector<pair<int, int>> edgeList;
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        edgeList.push_back({a, b});
    }
    for (auto i : edgeList)
    {
        cout << i.first << " " << i.second << endl;
    }
}
// When to use:
// When you want to iterate over all the edges of a graph in O(E) time.