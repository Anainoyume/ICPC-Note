#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define int long long

const int MAX_V = 1e4 + 5;

struct Edge {
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev): to(_to), cap(_cap), rev(_rev) {}
};

vector<Edge> G[MAX_V];
int a[MAX_V];
unordered_map<int, pair<int, int>> pre;

void add_edge(int from, int to, int cap) {
    G[from].push_back(Edge(to, cap, G[to].size()));
    G[to].push_back(Edge(from, 0, G[from].size() - 1));
}

void bfs(int s, int t) {
    memset(a, 0, sizeof(a));
    queue<int> que;
    que.push(s);
    a[s] = INF;
    while (!que.empty()) {
        int x = que.front();
        que.pop();
        for (int i = 0; i < G[x].size(); ++ i) {
            Edge& e = G[x][i];
            if (!a[e.to] && e.cap > 0) {
                pre[e.to] = make_pair(x, i);
                a[e.to] = min(a[x], e.cap);
                que.push(e.to);
            }
        }
        if (a[t]) break;
    }
}

int max_flow(int s, int t) {
    int ret = 0;
    while (1) {
        bfs(s, t);
        if (a[t] == 0) break;
        int u = t;
        while (u != s) {
            int p = pre[u].first, edge_index = pre[u].second;
            Edge& forward_edge = G[p][edge_index];
            Edge& reverse_edge = G[forward_edge.to][forward_edge.rev];
            forward_edge.cap -= a[t];
            reverse_edge.cap += a[t];
            u = reverse_edge.to;
        }
        ret += a[t];
    }
    return ret;
}

signed main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int from, to, cap;
        cin >> from >> to >> cap;
        add_edge(from,to,cap);
    }

    cout << max_flow(s,t) << endl;
    system("pause");
    return 0;
}
