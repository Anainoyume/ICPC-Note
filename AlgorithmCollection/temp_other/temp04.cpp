#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;

struct Edge
{
    int to, weight;
};


const int maxN = 205;
bool vis[maxN];
int dist[maxN];

vector<Edge> edges[maxN];
//head,dist和st用来存图结点，e,ne,和w用来存边
int n, m;

void dijkstra()
{
    //图的遍历
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});//first表示距离，second表示结点
    
    fill(dist, dist+maxN, INT_MAX);
    dist[1] = 0;
    
    while(!heap.empty())
    {
        auto [tempDis, cur] = heap.top();
        heap.pop();
        

        if(vis[cur]) continue;
        vis[cur] = true;
        
        //a->b, 已知a的距离和边权，去更新b的距离
        for(auto&& e : edges[cur])
        {
            auto [to, weight] = e;
            if(dist[to] > tempDis + weight)
            {
                dist[to] = tempDis + weight;    //这里更新全局的dist
                heap.push({dist[to], to});
            }
        }    
    }

}

int main()
{
    
    cin >> n; //n个结点, m条边
    
    for (int i = 1; i <= n-1; ++i) {
        for (int j = i+1; j <= n; ++j) {
            int w = 0;
            cin >> w;
            edges[i].push_back({j,w});
        }
    }
    
    dijkstra();
    
    if(dist[n] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
        

    system("pause");
    return 0;
}