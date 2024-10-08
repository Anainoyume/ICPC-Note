#include <bits/stdc++.h>
using namespace std;

using PII = pair<int,int>;

struct Edge
{
    int to, weight;
};


const int maxN = 1.5e5 + 10;
bool vis[maxN];
int dist[maxN];

vector<Edge> edges[maxN];
//结点数n 边数m s为开始结点
int n, m, s = 1;

void dijkstra()
{
    //图的遍历
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});//first表示距离，second表示结点
    
    fill(dist, dist+maxN, INT_MAX);
    fill(vis, vis+maxN, false);
    dist[s] = 0;
    
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

}

int main()
{
    cin >> n >> m >> s; //n个结点, m条边, 开始结点
    
    while(m--)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        edges[from].push_back({to,weight});
    }
    
    dijkstra();
    
    if(dist[n] == INT_MAX)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;
        

    system("pause");
    return 0;
}