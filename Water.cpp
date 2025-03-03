#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int left = v[0].second;
        int right = v[1].second;
        if (left > right)
        {
            swap(left, right);
        }
        cout << left << ' ' << right << endl;
    }
}