/* 
    Johnson ȫԴ���·���㷨
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
// ȫԴ dist ����
int dist[maxN][maxN];

int h[maxN];    // ��������
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
    //ͼ�ı���
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, s});//first��ʾ���룬second��ʾ���
    
    fill(dist[s], dist[s] + maxN, INT_MAX);
    fill(vis, vis+maxN, false);
    dist[s][s] = 0;
    
    while(!heap.empty())
    {
        auto [tempDis, cur] = heap.top();
        heap.pop();
        
        if(vis[cur]) continue;
        vis[cur] = true;
        
        //a->b, ��֪a�ľ���ͱ�Ȩ��ȥ����b�ľ���
        for(auto&& [to, weight] : edges[cur]) 
        {
            // ʹ�� ����h �Ż�
            if(!vis[to] && dist[s][to] > tempDis + (weight + h[cur] - h[to]))
            {
                dist[s][to] = tempDis + (weight + h[cur] - h[to]);    //�������ȫ�ֵ�dist
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

        // ��һ������ڵ�, �� 0�ŵ� ���������нڵ㶼��һ����ȨΪ 0 �ı�
        edges[0].push_back({from, 0});
    }

    // ����� 0 ��ÿ����� ���·��
    BellmanFord(0, n);

    // ÿ������һ�� dijkstra
    for (int i = 1; i <= n; ++i) {
        dijkstra(i);
    }

    // ע���������õ������·��������  u -> v �����·��Ϊ dis, �����Ǵ�����ֵΪ dis + h[u] - h[v]
    // �������ȡ������ʱ��Ҫ����ȥ
    // ����ʹ�� getPath ����

    int ans = 0;
    for (int i = 1; i <= m-1; ++i) {
        ans += getPath(path[i], path[i+1]);
    }

    cout << ans << endl;

    system("pause");
    return 0;
}