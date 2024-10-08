/* 
    Edmond_Karp算法，以下简称EK算法
    复杂度为 O(m^2*n), m为边的数量

    EK算法呢，实际上就是把DFS寻路变成了BFS而已
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long  
#define endl '\n'
const int maxN = 1e4+5;
int n, m, s, t; //n为点数，m为边数，s为源点，t为汇点

struct Edge
{
    //终点，容量，反向边
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};
vector<Edge> edges[maxN];
int vis[maxN]; //表示边的访问, 在dfs寻找路径时使用，同时记录从各个方向走到t点的最小流
int pre[maxN], lst[maxN];  //BFS时保留前驱，pre是前一个点，lst是前一个点的第几条边

void addEdge(int from, int to, int cap) {
    edges[from].push_back(Edge(to,cap,edges[to].size()));
    edges[to].push_back(Edge(from,0,edges[from].size()-1));
}

int bfs() {
    memset(vis,0,sizeof(vis));

    queue<int> que;
    que.push(s);

    vis[s] = INT64_MAX;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (int i = 0; i < edges[cur].size(); ++i) {
            auto [to,cap,rev] = edges[cur][i];
            if (!vis[to] && cap > 0) {
                lst[to] = i;
                pre[to] = cur;

                vis[to] = min(vis[cur],cap);    //只有这样才能记录从所有方向到t点的最小源，而不只是找到了直接break
                que.push(to);
            }
        }
        if (vis[t]) break;
    }

    // 找到了添加反向边
    if (vis[t]) {
        int cur = t;
        int prev = pre[cur];
        while (prev) {
            edges[prev][lst[cur]].cap -= vis[t];
            edges[cur][edges[prev][lst[cur]].rev].cap += vis[t];

            cur = prev;
            prev = pre[cur];
        }
        return vis[t];
    }
    else {
        return 0;
    }

}

signed main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int from, to, cap;
        cin >> from >> to >> cap;
        addEdge(from,to,cap);
    }
    
    int maxFlow = 0, f = 1;
    while (f = bfs()) {
        maxFlow += f;
    }

    cout << maxFlow << endl;

    system("pause");
    return 0;
}