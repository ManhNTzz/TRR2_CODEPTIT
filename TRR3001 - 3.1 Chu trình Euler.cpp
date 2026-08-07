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
int a[105][105];
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ifstream cin("CT.INP");
    ofstream cout("CT.OUT");
    int t;
    cin >> t;
    if (t == 1)
    {
        cin >> n;
        FOR(i, 1, n)
        FOR(j, 1, n)
            cin >> a[i][j];
        memset(vs, false, sizeof(vs));
        DFS(1);
        FOR(i, 1, n)
        {
            if (!vs[i])
            {
                cout << 0;
                return 0;
            }
        }
        int dem = 0;
        int bac[105] = {0};
        FOR(i, 1, n)
        FOR(j, 1, n)
        bac[i] += a[i][j];
        FOR(i, 1, n)
        if (bac[i] % 2 == 1)
            dem++;
        if (dem == 0)
            cout << 1;
        else if (dem == 2)
            cout << 2;
        else
            cout << 0;
    }
    else
    {
        cin >> n >> u;
        FOR(i, 1, n)
        FOR(j, 1, n)
            cin >> a[i][j];
        stack<int> st, ce;
        st.push(u);
        while (!st.empty())
        {
            int x = st.top();
            int ok = 0;
            FOR(i, 1, n)
            {
                if (a[x][i])
                {
                    st.push(i);
                    a[x][i] = a[i][x] = 0;
                    ok = 1;
                    break;
                }
            }
            if (!ok)
            {
                st.pop();
                ce.push(x);
            }
        }
        while (!ce.empty())
        {
            cout << ce.top() << " ";
            ce.pop();
        }
    }
}