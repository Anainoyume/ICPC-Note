#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxN = 1e4+5;
int n, m, s, t; //nΪ������mΪ������sΪԴ�㣬tΪ���

struct Edge
{
    //�յ㣬�����������
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) 
    : to(_to), cap(_cap), rev(_rev) 
    {}
};
vector<Edge> edges[maxN];
int deep[maxN]; //��¼ bfs �����
int record[maxN];   // ��ǰ���Ż�

void addEdge(int from, int to, int cap) {
    edges[from].push_back(Edge(to, cap, edges[to].size()));
    edges[to].push_back(Edge(from, 0, edges[from].size()-1));
}

// ���� level Graph
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

// Ѱ�� Block Graph
int dfs(int cur, int flow) {
    if (cur == t || (!flow)) return flow;

    int i{}, surp{flow};    //��ǰʣ������
    for (i = record[cur]; i < edges[cur].size() && surp; ++i) {
        record[cur] = i;    //�Ѿ�����������·�ı߲���Ҫ�ټ��������ˣ���¼���һ����Ҫ���µ�λ��
        auto [to, cap, rev] = edges[cur][i];

        if (cap && deep[to] == deep[cur]+1) {
            int maxflow{dfs(to, min(surp, cap))};
            if (!maxflow)   //��������, ����㲻��Ҫ�ٱ�����
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