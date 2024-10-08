#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+5;

#define endl '\n'

//第一个表示tempDis, 第二个表示编号
using PII = pair<int,int>;

struct Edge
{
    int to, weight;
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }
};
vector<Edge> edges[maxN];
bool vis[maxN];
int dist[maxN];

signed main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back({to,weight});
        edges[to].push_back({from,weight});
    }

    fill(dist, dist+maxN, INT_MAX);
    fill(vis, vis+maxN, false);
    dist[1] = 0;

    int ans = 0, cnt = 0;
    // Prim 算法
    priority_queue<PII,vector<PII>,greater<PII>> que;
    que.push({0,1});
    while (!que.empty()) {
        auto [tempDis, cur] = que.top();
        que.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        ans += tempDis;
        cnt += 1;
        for (auto&& [to, weight] : edges[cur]) {
            if (!vis[to] && dist[to] > weight) {
                dist[to] = weight;
                que.push({dist[to],to});
            }
        }
    }

    if (cnt == n) {
        cout << ans << endl;
    }
    else {
        cout << "orz" << endl;
    }

    system("pause");
    return 0;
}