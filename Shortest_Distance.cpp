#include <bits/stdc++.h>
using namespace std;
int n, e;
long long adjMat[105][105];
bool cycle;
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
    for (int i = 1; i <= n; i++)
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
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                adjMat[i][j] = 0;
            }
            else
            {
                adjMat[i][j] = LLONG_MAX;
            }
        }
    }
    cycle = false;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (adjMat[a][b] > c)
        {
            adjMat[a][b] = c;
        }
    }
    floydWarshall();
    int q;
    cin >> q;
    while (q--)
    {
        int src, des;
        cin >> src >> des;
        if (adjMat[src][des] == LLONG_MAX)

            cout << -1 << endl;
        else
            cout << adjMat[src][des] << endl;
    }
}