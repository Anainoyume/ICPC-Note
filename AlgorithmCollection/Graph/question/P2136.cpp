#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int maxN = 1e4+5;

struct Edge
{
    int to, weight;
};
vector<Edge> edges[maxN];
bool vis[maxN];
int dist[maxN];
int n, m, ans = INT_MAX;

bool BellmanFord(int s, int t) {
    fill(dist,dist+maxN,INT_MAX);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int cur = j;
            for (auto&& [to, weight] : edges[cur]) {
                dist[to] = min(dist[to],dist[cur]+weight);
            }
        }
    }

    bool flag = false;
    for (int j = 1; j <= n; j++) {
        int cur = j;
        for (auto&& [to, weight] : edges[cur]) {
            if (to == t && dist[to] > dist[cur]+weight) {
                flag = true;
            }
        }
        if (flag) break;
    }

    if (flag)
        return true;
    else
        ans = min(ans,dist[t]);
    return false;
}

signed main()
{
    
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        weight *= -1;
        edges[from].push_back({to,weight});
    }
    
    bool flag1 = BellmanFord(1,n);
    bool flag2 = BellmanFord(n,1);
    
    if (flag1 || flag2)
        cout << "Forever love" << endl;
    else
        cout << ans << endl;

    system("pause");
    return 0;
}