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

set<int> res;
int a[105][105];
bool vs[105];
int n;
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
                qe.push(i);
                vs[i] = true;
            }
        }
    }
}
int demtplt()
{
    int cnt = 0;
    FOR(i, 1, n)
    {
        if (vs[i])
            continue;
        BFS(i);
        cnt++;
    }
    return cnt;
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
    memset(vs, false, sizeof(vs));
    int dem = demtplt();
    FOR(i, 1, n)
    {
        memset(vs, false, sizeof(vs));
        vs[i] = true;
        if (dem < demtplt())
            res.insert(i);
    }
    cout << res.size() << endl;
    for (auto x : res)
        cout << x << " ";

    return 0;
}