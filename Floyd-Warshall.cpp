#include <bits/stdc++.h>
using namespace std;
int n, e;
int adjMat[100][100];
bool cycle;
void floydWarshall()
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adjMat[i][k] != INT_MAX && adjMat[k][j] != INT_MAX && adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (adjMat[i][i] < 0)
        {
            cycle = true;
            break;
        }
    }
}
int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                adjMat[i][j] = 0;
            }
            else
            {
                adjMat[i][j] = INT_MAX;
            }
        }
    }
    cycle = false;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adjMat[a][b] = c;
    }
    floydWarshall();
    if (cycle)
    {
        cout << "Negative weighted cycle detected" << endl;
    }
    else
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << adjMat[i][j] << ' ';
            }
            cout << endl;
        }
}