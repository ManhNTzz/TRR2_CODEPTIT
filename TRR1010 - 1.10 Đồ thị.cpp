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

// Cre by ManhNTzz

const int INF = 1e9;
set<vector<int>> dsc;
int bac[105] = {0};
int t, n;
int a[105][105] = {};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    cin >> t >> n;
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        int x;
        cin >> x;
        if (x > 0 && x <= 50 && j >= i + 1)
        {
            a[i][j] = x;
            bac[i]++;
            bac[j]++;
            dsc.insert({i, j});
        }
    }
    if (t == 1)
        FOR(i, 1, n)
    cout << bac[i] << " ";
    else
    {
        cout << n << " " << dsc.size() << endl;
        for (auto v : dsc)
        {
            cout << v[0] << " " << v[1] << " " << a[v[0]][v[1]] << endl;
        }
    }
    return 0;
}