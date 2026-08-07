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
vector<vector<int>> a(105, vector<int>(105, 10000));
int bac[105] = {};
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
        int x, y, z;
        cin >> x >> y >> z;
        a[x][y] = a[y][x] = z;
        bac[x]++;
        bac[y]++;
    }
    if (t == 1)
        FOR(i, 1, n)
    cout << bac[i] << " ";
    else
    {
        cout << n << endl;
        FOR(i, 1, n)
        {
            FOR(j, 1, n)
            {
                if (i == j)
                    cout << 0 << " ";
                else
                    cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}