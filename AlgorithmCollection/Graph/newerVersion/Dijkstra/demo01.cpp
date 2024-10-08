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
//�����n ����m sΪ��ʼ���
int n, m, s = 1;

void dijkstra()
{
    //ͼ�ı���
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});//first��ʾ���룬second��ʾ���
    
    fill(dist, dist+maxN, INT_MAX);
    fill(vis, vis+maxN, false);
    dist[s] = 0;
    
    while(!heap.empty())
    {
        auto [tempDis, cur] = heap.top();
        heap.pop();
        
        if(vis[cur]) continue;
        vis[cur] = true;
        
        //a->b, ��֪a�ľ���ͱ�Ȩ��ȥ����b�ľ���
        for(auto&& [to, weight] : edges[cur])
        {
            if(!vis[to] && dist[to] > tempDis + weight)
            {
                dist[to] = tempDis + weight;    //�������ȫ�ֵ�dist
                heap.push({dist[to], to});
            }
        }    
    }

}

int main()
{
    cin >> n >> m >> s; //n�����, m����, ��ʼ���
    
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