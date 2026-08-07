#include <bits/stdc++.h>
using namespace std;

// Cre by ManhNTzz

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // fstream cin("DT.INP", ios::in);
    // fstream out("DT.OUT", ios::out);
    int t, n;
    cin >> t >> n;
    int a[105][105];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            int deg = 0;
            for (int j = 1; j <= n; j++)
                deg += a[i][j];
            cout << deg << " ";
        }
    }
    else if (t == 2)
    {
        vector<pair<int, int>> edge;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (a[i][j] == 1)
                    edge.push_back({i, j});
        cout << n << " " << edge.size() << endl;
        for (auto e : edge)
            cout << e.first << " " << e.second << endl;
    }
}
