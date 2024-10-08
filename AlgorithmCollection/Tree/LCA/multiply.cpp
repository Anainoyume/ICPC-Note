#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e5+5;
// f[i][j] 为 点i的 第 2^j 个祖先, deep为深度
int f[maxN][32], deep[maxN];
vector<int> edges[maxN];

int n, q, st;

void getDeep(int cur, int parent) {
    deep[cur] = deep[parent] + 1;
    f[cur][0] = parent;
    for(int i = 1; (1 << i) <= deep[cur]; ++i) {
        f[cur][i] = f[f[cur][i-1]][i-1];
    }

    for (auto&& to : edges[cur]) {
        if (to == parent) continue;
        getDeep(to,cur);
    }
}

int lca(int u, int v) {
    int log2n = log(n)/log(2) + 0.5;

    int uDeep = deep[u], vDeep = deep[v];
    if (uDeep != vDeep) {
        if (uDeep < vDeep) {
            swap(u,v);
            swap(uDeep,vDeep);
        }
        int d = uDeep - vDeep;
        for (int i = 0; i <= log2n; ++i) {
            if ((1 << i) & d) u = f[u][i];
        }
    }

    if (u == v) return u;

    for (int i = log2n; i >= 0; --i)
	{
		if (deep[f[u][i]] <= 0) continue;
		if (f[u][i] == f[v][i]) continue;   //注意我们寻找的是最近的公共祖先, 同时注意我们返回的是 f[u][0]
		else u = f[u][i], v = f[v][i];
	}
	return f[u][0];
}

signed main()
{
    
    cin >> n >> q >> st;
    for (int i = 1; i <= n-1; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }

    getDeep(st,0);

    for (int i = 1; i <= q; ++i) {
        int u, v;
        cin >> u >> v;
        cout << lca(u,v) << endl;
    }

    system("pause");
    return 0;
}