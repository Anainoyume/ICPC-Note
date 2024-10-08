/* 
    Johnson 全源最短路径算法
 */
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

const int maxN = 105;

struct Edge {
    int to, weight;
};

int n, m;
vector<Edge> edges[maxN];
bool vis[maxN];
// 全源 dist 数组
int dist[maxN][maxN];

int h[maxN];    // 势能数组
void BellmanFord(int s, int t) {
    fill(h,h+maxN,INT_MAX);
    h[s] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int cur = j;
            for (auto&& [to, weight] : edges[cur]) {
                h[to] = min(h[to],h[cur]+weight);
            }
        }
    }
}


void dijkstra(int s)
{
    //图的遍历
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, s});//first表示距离，second表示结点
    
    fill(dist[s], dist[s] + maxN, INT_MAX);
    fill(vis, vis+maxN, false);
    dist[s][s] = 0;
    
    while(!heap.empty())
    {
        auto [tempDis, cur] = heap.top();
        heap.pop();
        
        if(vis[cur]) continue;
        vis[cur] = true;
        
        //a->b, 已知a的距离和边权，去更新b的距离
        for(auto&& [to, weight] : edges[cur]) 
        {
            // 使用 势能h 优化
            if(!vis[to] && dist[s][to] > tempDis + (weight + h[cur] - h[to]))
            {
                dist[s][to] = tempDis + (weight + h[cur] - h[to]);    //这里更新全局的dist
                heap.push({dist[s][to], to});
            }
        }    
    }
}

inline int getPath(int from, int to) {
    return dist[from][to] - h[from] + h[to];
}

signed main()
{
    cin >> n >> m;
    vector<int> path(m+1,0);
    for (int i = 1; i <= m; ++i) {
        cin >> path[i];
    }

    for (int from = 1; from <= n; ++from) {
        for (int to = 1; to <= n; ++to) {
            int weight;
            cin >> weight;
            edges[from].push_back({to, weight});
        }

        // 建一个虚拟节点, 从 0号点 先其他所有节点都连一条边权为 0 的边
        edges[0].push_back({from, 0});
    }

    // 先求出 0 到每个点的 最短路径
    BellmanFord(0, n);

    // 每个点跑一遍 dijkstra
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
    }

    // 注意我们最后得到的最短路径，假如  u -> v 的最短路径为 dis, 则我们存贮的值为 dis + h[u] - h[v]
    // 因此我们取出来的时候要减回去
    // 我们使用 getPath 方法

    int ans = 0;
    for (int i = 1; i <= m-1; ++i) {
        ans += getPath(path[i], path[i+1]);
    }

    cout << ans << endl;

    system("pause");
    return 0;
}