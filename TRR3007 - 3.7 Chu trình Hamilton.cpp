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

int n, u;
bool vs[105];
int a[105][105], path[105];
int cnt = 0;
void Hamilton(int i)
{
    FOR(j, 1, n)
    {
        if (a[path[i - 1]][j] && !vs[j])
        {
            vs[j] = true;
            path[i] = j;
            if (i == n)
            {
                if (a[j][u])
                {
                    FOR(i, 1, n)
                    cout << path[i] << " ";
                    cout << u << endl;
                    cnt++;
                }
            }
            else
                Hamilton(i + 1);
            vs[j] = false;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CT.INP", "r", stdin);
    freopen("CT.OUT", "w", stdout);
    cin >> n >> u;
    FOR(i, 1, n)
    FOR(j, 1, n)
        cin >> a[i][j];
    memset(vs, false, sizeof(vs));
    path[1] = u;
    vs[u] = true;
    Hamilton(2);
    cout << cnt;
    return 0;
}