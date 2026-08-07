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

int a[105][105];
bool vs[105];
vector<pair<int, int>> res;
int n, s;
void DFS(int u)
{
    vs[u] = true;
    FOR(i, 1, n)
    {
        if (!vs[i] && a[u][i])
        {
            res.pb({u, i});
            DFS(i);
        }
    }
}
void BFS(int u)
{
    vs[u] = true;
    queue<int> qe;
    qe.push(u);
    while (!qe.empty())
    {
        int x = qe.front();
        qe.pop();
        FOR(i, 1, n)
        {
            if (!vs[i] && a[x][i])
            {
                res.pb({x, i});
                qe.push(i);
                vs[i] = true;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    int t;
    cin >> t;
    cin >> n >> s;
    FOR(i, 1, n)
    FOR(j, 1, n)
        cin >> a[i][j];
    if (t == 1)
        DFS(s);
    else
        BFS(s);
    if (res.size() == n - 1)
    {
        cout << res.size() << endl;
        for (auto v : res)
            cout << min(v.fi, v.se) << " " << max(v.fi, v.se) << endl;
    }
    else
        cout << 0;

    return 0;
}