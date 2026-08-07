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

vector<set<int>> dsk(105);
int vao[105] = {0};
int ra[105] = {0};
int t, n, m;
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
        vao[y]++;
        ra[x]++;
        dsk[x].insert(y);
    }
    if (t == 1)
        FOR(i, 1, n)
    cout << vao[i] << " " << ra[i] << endl;
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