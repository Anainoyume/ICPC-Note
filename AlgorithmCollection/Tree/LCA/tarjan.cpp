#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int f[maxN];
bool vis[maxN];
vector<int> edges[maxN];
vector<pair<int,int>> query[maxN];
int ans[maxN];

int find(int x) {
    return x == f[x] ? x : find(f[x]);
}


void dfs(int cur, int parent) {
    for (auto&& to : edges[cur]) {
        if (to != parent) {
            dfs(to,cur);
            f[to] = cur;
            vis[to] = true;
        }
    }

    // 处理所有关联结点
    if (!query[cur].empty()) {
        for (auto&& [to, index] : query[cur]) {
            if (vis[to]) {
                ans[index] = find(to);
            }
        }
    }
}

signed main()
{
    int n, m, st;
    cin >> n >> m >> st;
    for (int i = 1; i <= n-1; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    for (int i = 1; i <= n; ++i) {
        f[i] = i;
    }
    
    for (int i = 1; i <= m; ++i) {
        int v, u;
        cin >> v >> u;
        query[v].push_back({u,i});
        query[u].push_back({v,i});
    }

    dfs(st,0);

    for (int i = 1; i <= m; ++i) {
        cout << ans[i] << endl;
    }
    

    system("pause");
    return 0;
}