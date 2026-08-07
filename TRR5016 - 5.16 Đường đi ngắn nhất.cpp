#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FOD(i, a, b) for (int i = (b); i >= (a); --i)
#define ll long long
#define se second
#define fi first
#define len length()
#define ALL(s) s.begin(), s.end()
#define vi vector<int>
#define vb vector<bool>
#define vll vector<long long>
#define pb push_back
const long long mod = 1000000007;
const int INF = 1e9;

// Cre by ManhNTzz

int a[105][105], Next[105][105], d[105][105];
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("DN.INP");
    ofstream cout("DN.OUT");
    cin >> n;
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        cin >> a[i][j];
        d[i][j] = a[i][j];
        if (i != j && a[i][j] != 10000)
        {
            Next[i][j] = j;
        }
        else
            Next[i][j] = 0;
    }
    FOR(k, 1, n)
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        if (d[i][j] > d[i][k] + d[k][j])
        {
            d[i][j] = d[i][k] + d[k][j];
            Next[i][j] = Next[i][k];
        }
    }
    int u = -1, v = -1, max_val = 0;
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        if (i != j && d[i][j] != 10000 && d[i][j] > max_val)
        {
            max_val = d[i][j];
            u = i;
            v = j;
        }
    }
    if (u != -1)
    {
        cout << u << " " << v << " " << max_val << endl;
        int curr = u;
        while (1)
        {
            cout << curr << " ";
            if (curr == v)
                break;
            curr = Next[curr][v];
        }
    }
    else
        cout << 0;

    return 0;
}