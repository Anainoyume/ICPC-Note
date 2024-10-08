// 割边
#include <iostream>
#include <vector>
using namespace std;

const int maxN = 1e5 + 1;

int low[maxN], dfn[maxN], dfs_clock;
bool isbridge[maxN];
vector<int> edges[maxN];
int cnt_bridge;
int father[maxN];

void tarjan(int cur, int fa) {
    father[cur] = fa;
    low[cur] = dfn[cur] = ++dfs_clock;

    for (auto&& to : edges[cur]) {
        if (!dfn[to]) {
            tarjan(to, cur);
            low[cur] = min(low[cur], low[to]);
            
            if (low[to] > dfn[cur]) {
                isbridge[to] = true;
                ++cnt_bridge;
            }
        }
        else if (dfn[to] < dfn[cur] && to != fa) {
            low[cur] = min(low[cur], dfn[to]);
        }
    }
}

// 判断是否为割边
bool isCutEdge(int u, int v) {
    return ((isbridge[u] && father[u] == v) || (isbridge[v] && father[v] == u));
}

//如果存在 isbridge[x] 为 true，那么 ( father[x], x ) 为一条割边

signed main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    for (int i = 1; i <= n; i++) {
        if (!father[i]) {
            dfs_clock = 0;     
            tarjan(i, i); 
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (isbridge[i]) {
            cout << father[i] << " " << i << endl;
        }
    }

    system("pause");
    return 0;
}