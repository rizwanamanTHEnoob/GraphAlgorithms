#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nodes, edges;
    cin >> nodes >> edges;
    int matrix[nodes][nodes];
    memset(matrix, 0, sizeof(matrix));
    while (edges--)
    {
        int a, b;
        cin >> a >> b;
        matrix[a][b] = 1;
        matrix[b][a] = 1; // For undirected graph
    }
    for (int i = 0; i < nodes; i++)
    {
        matrix[i][i] = 1; 
    }
    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
// When to use:
// When you want to check if there is an edge between two nodes in O(1) time.
