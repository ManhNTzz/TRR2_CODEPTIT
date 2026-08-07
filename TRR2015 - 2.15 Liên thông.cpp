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
int n;
bool vs[105];
void DFS(int u)
{
    vs[u] = true;
    FOR(i, 1, n)
    {
        if (!vs[i] && a[u][i])
            DFS(i);
    }
}
void checklt(int u)
{
    vs[u] = true;
    FOR(i, 1, n)
    {
        if (!vs[i] && (a[u][i] || a[i][u]))
            checklt(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("TK.INP");
    ofstream cout("TK.OUT");
    cin >> n;
    FOR(i, 1, n)
    FOR(j, 1, n)
        cin >> a[i][j];
    int ok = 0;
    FOR(u, 1, n)
    {
        memset(vs, false, sizeof(vs));
        DFS(u);
        FOR(v, 1, n)
        {
            if (!vs[v])
            {
                ok = 1;
                break;
            }
        }
    }
    if (!ok)
    {
        cout << 1;
    }
    else
    {
        memset(vs, false, sizeof(vs));
        int check = 0;
        checklt(1);
        FOR(i, 1, n)
        {
            if (!vs[i])
            {
                check = 1;
                break;
            }
        }
        if (!check)
            cout << 2;
        else
            cout << 0;
    }
    return 0;
}