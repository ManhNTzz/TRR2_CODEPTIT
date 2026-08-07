#include <bits/stdc++.h>
using namespace std;
#define maxn 105

// Cre by ManhNTzz

int n, E, st;
int a[maxn][maxn] = {};
bool vis[maxn] = {};
set<int> ke[maxn];
vector<vector<int>> res;

void DFS(int u)
{
    vis[u] = true;
    for (int v : ke[u])
    {
        if (!vis[v])
        {
            res.push_back({u, v});
            DFS(v);
        }
    }
}

void BFS()
{
    for (bool &b : vis)
        b = false;
    queue<int> qe;
    qe.push(st);
    vis[st] = true;
    while (!qe.empty())
    {
        int u = qe.front();
        qe.pop();
        for (int v : ke[u])
        {
            if (!vis[v])
            {
                res.push_back({u, v});
                vis[v] = true;
                qe.push(v);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("CK.INP", "r", stdin);
    // freopen("CK.OUT", "w", stdout);
    int k;
    cin >> k >> n >> E >> st;

    for (int i = 1; i <= E; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x][y] = 1;
        ke[x].insert(y);
    }

    if (k == 1)
        DFS(st);
    else
        BFS();

    if (res.size() == n - 1)
    {
        cout << res.size() << endl;
        for (vector<int> v : res)
            cout << v[0] << " " << v[1] << endl;
    }
    else
        cout << "0" << endl;

    return 0;
}