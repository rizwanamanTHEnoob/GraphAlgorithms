#include <bits/stdc++.h>
using namespace std;
long long int n, m, q;
long long int adjMat[505][505];
void floydWarshall()
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (adjMat[i][k] != LLONG_MAX && adjMat[k][j] != LLONG_MAX && adjMat[i][k] + adjMat[k][j] < adjMat[i][j])
                {
                    adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
                }
            }
        }
    }
}
int main()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            adjMat[i][j] = LLONG_MAX;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        adjMat[i][i] = 0;
    }
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < adjMat[a][b])
        {
            adjMat[a][b] = c;
            adjMat[b][a] = c;
        }
    }
    floydWarshall();
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (adjMat[a][b] == LLONG_MAX)
        {
            cout << -1 << endl;
        }
        else
            cout << adjMat[a][b] << endl;
    }
}