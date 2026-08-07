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

struct Edge
{
    int u, v, w;
};
int n, m;
vector<Edge> T;
vector<Edge> res;
int WT = 0;
int parent[105];
int Find(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = Find(parent[v]);
}
bool Union(int u, int v)
{
    u = Find(u);
    v = Find(v);
    if (u != v)
    {
        parent[v] = u;
        return true;
    }
    return false;
}
bool cmp(Edge a, Edge b)
{
    if (a.w == b.w && a.u == b.u)
        return a.v < b.v;
    else if (a.w == b.w)
        return a.u < b.u;
    return a.w < b.w;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CK.INP", "r", stdin);
    freopen("CK.OUT", "w", stdout);
    cin >> n >> m;
    T.resize(m);
    REP(i, m)
    cin >> T[i].u >> T[i].v >> T[i].w;
    sort(ALL(T), cmp);
    FOR(i, 1, n)
    parent[i] = i;
    REP(i, m)
    {
        if (Union(T[i].u, T[i].v))
        {
            res.pb(T[i]);
            WT += T[i].w;
            if (res.size() == n - 1)
                break;
        }
    }
    if (res.size() == n - 1)
    {
        cout << WT << endl;
        for (auto e : res)
            cout << e.u << " " << e.v << " " << e.w << endl;
    }
    else
        cout << 0;

    return 0;
}