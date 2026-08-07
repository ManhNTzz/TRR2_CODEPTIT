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
vector<set<int>> dsk(105);
int t, n, m;
int bac[105] = {0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("DT.INP");
    ofstream cout("DT.OUT");
    cin >> t >> n >> m;
    REP(i, m)
    {
        int x, y;
        cin >> x >> y;
        bac[x]++;
        bac[y]++;
        dsk[x].insert(y);
        dsk[y].insert(x);
    }
    if (t == 1)
        FOR(i, 1, n)
    cout << bac[i] << " ";
    else
    {
        cout << n << endl;
        FOR(i, 1, n)
        {
            cout << dsk[i].size() << " ";
            for (auto x : dsk[i])
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}