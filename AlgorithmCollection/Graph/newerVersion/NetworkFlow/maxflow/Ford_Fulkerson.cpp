/* 
    Ford_Fulkerson算法，以下简称FF算法
    复杂度极高，因此仅供学习参考用
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
bool vis[maxN]; //表示边的访问, 在dfs寻找路径时使用

void addEdge(int from, int to, int cap) {
    //这是使用vector进行加边的一个处理技巧，使用vector写网络流算法最麻烦的难以寻找反向边，在这里我们可以这样处理
    //from加入的反向边to，在to中，恰好是第下标为edges[to].size()要被加入的元素
    edges[from].push_back(Edge(to,cap,edges[to].size()));
    //同理，from加入了一个,edges[from].size()多了1，我们再减一个1，就拿到了上面我们要的反向边下标
    //注意反向边一开始的cap要为0
    edges[to].push_back(Edge(from,0,edges[from].size()-1));
}

int dfs(int cur, int minflow) {
    if (cur == t) {
        return minflow; //找到了终点，返回minflow
    }
    vis[cur] = true;

    for (int i = 0; i < edges[cur].size(); ++i) {
        auto [to, cap, rev] = edges[cur][i];
        // vis防止重复访问死循环， cap > 0 要求不是被移除的边
        if (!vis[to] && cap > 0) {
            int d = dfs(to,min(minflow,cap));
            // 从底层dfs返回如果d != 0 ，说明找到了汇点t
            if (d > 0) {
                edges[cur][i].cap -= d; //当前边减去d的流量
                edges[to][rev].cap += d;    //反向边加上d的流量
                return d;
            }
        }
    }

    //如果一切操作都不能进行，或者没有边了，说明没有找到汇点t
    return 0;   //返回0表示失败状态
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
    
    int flow = 0, f = 1;
    while (f = dfs(s,INT64_MAX)) {
        fill(vis,vis+maxN,false);
        flow += f;
    }
    cout << flow << endl;

    system("pause");
    return 0;
}