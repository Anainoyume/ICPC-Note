/* 
    Edmond_Karp�㷨�����¼��EK�㷨
    ���Ӷ�Ϊ O(m^2*n), mΪ�ߵ�����

    EK�㷨�أ�ʵ���Ͼ��ǰ�DFSѰ·�����BFS����
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long  
#define endl '\n'
const int maxN = 1e4+5;
int n, m, s, t; //nΪ������mΪ������sΪԴ�㣬tΪ���

struct Edge
{
    //�յ㣬�����������
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};
vector<Edge> edges[maxN];
int vis[maxN]; //��ʾ�ߵķ���, ��dfsѰ��·��ʱʹ�ã�ͬʱ��¼�Ӹ��������ߵ�t�����С��
int pre[maxN], lst[maxN];  //BFSʱ����ǰ����pre��ǰһ���㣬lst��ǰһ����ĵڼ�����

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

                vis[to] = min(vis[cur],cap);    //ֻ���������ܼ�¼�����з���t�����СԴ������ֻ���ҵ���ֱ��break
                que.push(to);
            }
        }
        if (vis[t]) break;
    }

    // �ҵ�����ӷ����
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