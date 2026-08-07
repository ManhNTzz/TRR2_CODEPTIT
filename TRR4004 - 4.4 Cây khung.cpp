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

int n, s;
int a[105][105];
struct Edge
{
    int u, v, w;
};
int WT = 0;
vector<Edge> res;
bool vs[105];
void Prim(int s)
{
    vs[s] = true;
    int ok = 0;
    FOR(i, 1, n - 1)
    {
        int min_u = -1, min_v = -1, min_w = 10000;
        FOR(u, 1, n)
        {
            if (vs[u])
            {
                FOR(v, 1, n)
                {
                    if (!vs[v])
                    {
                        if (a[u][v] != 0 && a[u][v] < min_w)
                        {
                            min_w = a[u][v];
                            min_u = u;
                            min_v = v;
                            ok = 1;
                        }
                    }
                }
            }
        }
        if (min_u != -1)
        {
            WT += min_w;
            res.pb({min(min_u, min_v), max(min_u, min_v), min_w});
            vs[min_v] = true;
        }
    }
    if (!ok)
        cout << 0;
    else
    {
        cout << WT << endl;
        for (auto e : res)
            cout << e.u << " " << e.v << " " << e.w << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> s;
    memset(vs, false, sizeof(vs));
    FOR(i, 1, n)
    FOR(j, 1, n)
        cin >> a[i][j];
    Prim(s);

    return 0;
}