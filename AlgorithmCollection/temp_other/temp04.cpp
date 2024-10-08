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
//head,dist��st������ͼ��㣬e,ne,��w�������
int n, m;

void dijkstra()
{
    //ͼ�ı���
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});//first��ʾ���룬second��ʾ���
    
    fill(dist, dist+maxN, INT_MAX);
    dist[1] = 0;
    
    while(!heap.empty())
    {
        auto [tempDis, cur] = heap.top();
        heap.pop();
        

        if(vis[cur]) continue;
        vis[cur] = true;
        
        //a->b, ��֪a�ľ���ͱ�Ȩ��ȥ����b�ľ���
        for(auto&& e : edges[cur])
        {
            auto [to, weight] = e;
            if(dist[to] > tempDis + weight)
            {
                dist[to] = tempDis + weight;    //�������ȫ�ֵ�dist
                heap.push({dist[to], to});
            }
        }    
    }

}

int main()
{
    
    cin >> n; //n�����, m����
    
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