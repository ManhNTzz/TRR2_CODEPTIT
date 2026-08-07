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

int a[105][105], d[105], truoc[105];
int n, s, t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DN.INP", "r", stdin);
    freopen("DN.OUT", "w", stdout);
    cin >> n >> s >> t;
    FOR(i, 1, n)
    FOR(j, 1, n)
        cin >> a[i][j];
    FOR(i, 1, n)
    {
        d[i] = 10000;
        truoc[i] = 0;
    }
    d[s] = 0;
    int k = 0;
    while (k <= n - 1)
    {
        int ok = 0;
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                if (d[j] != 10000 && a[j][i] != 0 && a[j][i] != 10000)
                {
                    if (d[i] > d[j] + a[j][i])
                    {
                        d[i] = d[j] + a[j][i];
                        truoc[i] = j;
                        ok = 1;
                    }
                }
            }
        }
        if (!ok)
            break;
        k++;
    }
    int checkchutrinham = 0;
    FOR(i, 1, n)
    FOR(j, 1, n)
    {
        if (d[i] > d[j] + a[j][i])
        {
            checkchutrinham = 1;
            break;
        }
    }
    if (checkchutrinham)
        cout << -1;
    else if (d[t] == 10000)
        cout << 0;
    else
    {
        cout << d[t] << endl;
        vector<int> res;
        int curr = t;
        while (1)
        {
            res.pb(curr);
            if (curr == s)
                break;
            curr = truoc[curr];
        }
        reverse(ALL(res));
        for (auto x : res)
            cout << x << " ";
    }
    return 0;
}