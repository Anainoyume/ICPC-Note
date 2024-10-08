#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 1e4+5;
int n, m, s, t; //n为点数，m为边数，s为源点，t为汇点

struct Edge
{
    //终点，容量，反向边
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) 
    : to(_to), cap(_cap), rev(_rev) 
    {}
};
vector<Edge> edges[maxN];
int deep[maxN]; //记录 bfs 的深度
int record[maxN];   // 当前弧优化

void addEdge(int from, int to, int cap) {
    edges[from].push_back(Edge(to, cap, edges[to].size()));
    edges[to].push_back(Edge(from, 0, edges[from].size()-1));
}

// 构造 level Graph
bool bfs() {
    queue<int> que;
    fill(deep,deep+maxN,0);

    que.push(s);
    deep[s] = 1, record[s] = 0;

    while (!que.empty()) {
        int cur = que.front();
        que.pop();

        for (auto&& [to, cap, rev] : edges[cur]) {
            if (!deep[to] && cap) {
                record[to] = 0;
                deep[to] = deep[cur] + 1;
                que.push(to);
            }
        }
    }

    return deep[t];
}

// 寻找 Block Graph
int dfs(int cur, int flow) {
    if (cur == t || (!flow)) return flow;

    int i{}, surp{flow};    //当前剩余流量
    for (i = record[cur]; i < edges[cur].size() && surp; ++i) {
        record[cur] = i;    //已经更新完增广路的边不需要再继续更新了，记录最后一个需要更新的位置
        auto [to, cap, rev] = edges[cur][i];

        if (cap && deep[to] == deep[cur]+1) {
            int maxflow{dfs(to, min(surp, cap))};
            if (!maxflow)   //增广完了, 这个点不需要再遍历了
                deep[to] = 0;  

            edges[cur][i].cap -= maxflow;   
            edges[to][edges[cur][i].rev].cap += maxflow;

            surp -= maxflow;
        }
        
    }
    return flow - surp;
}

int Dinic() {
    int res{}, flow{};
    while (bfs()) {
        while (flow = dfs(s, INT_MAX))
            res += flow;
    }
    return res;
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
    
    cout << Dinic() << endl;

    system("pause");
    return 0;
}