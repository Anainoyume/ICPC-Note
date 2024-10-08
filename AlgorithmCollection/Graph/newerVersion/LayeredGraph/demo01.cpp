/*
    分层图
*/
#include <bits/stdc++.h>
using namespace std;

//#define int long long

#define endl '\n'

#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

const int maxN = 5e5+5;
int n, m, k;

struct Edge
{
    int to, weight;
};

vector<Edge> edges[maxN];

#define getPoint(x, a) ((x)+(a)*n)

int dist[maxN];
bool vis[maxN];
int dijkstra(int st, int ed)
{
    //图的遍历
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
    heap.push({0, st});//first表示距离，second表示结点
    
    fill(dist, dist+maxN, INT_MAX);
    fill(vis, vis+maxN, false);
    dist[st] = 0;
    
    while(!heap.empty())
    {
        auto [tempDis, cur] = heap.top();
        heap.pop();
        

        if(vis[cur]) continue;
        vis[cur] = true;
        
        //a->b, 已知a的距离和边权，去更新b的距离
        for(auto&& [to, weight] : edges[cur])
        {
            if(!vis[to] && dist[to] > tempDis + weight)
            {
                dist[to] = tempDis + weight;    //这里更新全局的dist
                heap.push({dist[to], to});
            }
        }    
    }

    int ans = INT_MAX;
    for (int i = 0; i <= k; ++i) {
        ans = min(ans,dist[getPoint(ed,k)]);
    }
    return ans;
}

signed main()
{
    IOS;

    int st, ed;
    cin >> n >> m >> k;
    cin >> st >> ed;

    k = min(k,m);

    for (int i = 1; i <= m; ++i) {
        int from, to, money;
        cin >> from >> to >> money;

        for (int j = 0; j <= k; ++j) {
            edges[getPoint(from,j)].push_back({getPoint(to,j),money});
            edges[getPoint(to,j)].push_back({getPoint(from,j),money});

            if (j >= 1) {
                edges[getPoint(from,j-1)].push_back({getPoint(to,j),0});
                edges[getPoint(to,j-1)].push_back({getPoint(from,j),0});
            }
        }
        
    }

    cout << dijkstra(st,ed) << endl;


    system("pause");
    return 0;
}