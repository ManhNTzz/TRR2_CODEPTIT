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
#define ALLN(s) s.rbegin(), s.rend()
const long long mod = 1000000007;

// Cre by ManhNTzz

int a[105][105], d[105], truoc[105], vs[105];
int n, s, t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("BN.INP");
    ofstream cout("BN.OUT");
    if (!(cin >> n >> s >> t))
        return 0;
    FOR(i, 1, n)
    FOR(j, 1, n)
        cin >> a[i][j];
    FOR(i, 1, n)
    {
        d[i] = 10000;
        truoc[i] = 0;
    }
    d[s] = 0;
    int k = 1;
    while (k <= n - 1)
    {
        bool update = false;
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                if (d[j] != 10000 && a[j][i] != 10000 && a[j][i] != 0)
                {
                    if (d[i] > d[j] + a[j][i])
                    {
                        d[i] = d[j] + a[j][i];
                        truoc[i] = j;
                        update = true;
                    }
                }
            }
        }
        if (!update)
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
    if (checkchutrinham == 1)
        cout << -1;
    else if (d[t] == 10000)
        cout << 0;
    else
    {
        cout << d[t] << endl;
        vector<int> duongdi;
        int curr = t;
        while (1)
        {
            duongdi.push_back(curr);
            curr = truoc[curr];
            if (curr == s)
            {
                duongdi.push_back(s);
                break;
            }
        }
        reverse(ALL(duongdi));
        for (auto x : duongdi)
            cout << x << " ";
        return 0;
    }
    return 0;
}