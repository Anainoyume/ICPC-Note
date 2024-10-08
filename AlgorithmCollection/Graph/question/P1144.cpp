#include <bits/stdc++.h>
using namespace std;
/* 
    P1144 ���·����
    һ��ͼ��dp��Dijkstra�����ڻ����������и�Ȩ��
    ͼ��dp����ΪDAG���������޻�ͼ����ʵ������һ������������"��״���ͼ"����⣬������dp
    ��һ�ִ��ڻ������ͣ���ʹ�����·����DFS+���仯��������������
 */
#define endl '\n'
#define int long long
const int maxN = 1e6+5;
const int md = 1e5+3;
using PII = pair<int,int>;

struct Edge
{
    int to, weight;
};

vector<Edge> edges[maxN];
bool vis[maxN];
int dist[maxN];
int ans[maxN];

int n, m;

signed main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        if (from == to) continue;
        edges[from].push_back({to,1});
        edges[to].push_back({from,1});  //����ͼ, fuck
    }
    fill(dist,dist+maxN,INT_MAX);
    dist[1] = 0;
    ans[1] = 1;

    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});

    while (!heap.empty()) {
        auto [tempDis, cur] = heap.top();
        heap.pop();

        if (vis[cur]) continue;
        vis[cur] = true;

        for (auto&& [to, weight] : edges[cur]) {
            if (!vis[to] && dist[to] > dist[cur]+weight) {
                dist[to] = dist[cur]+weight;
                heap.push({dist[to],to});
                ans[to] = ans[cur];
                ans[to] %= md;  //����������±����ã���ô����
            }
            else if (dist[to] == dist[cur]+weight) {
                ans[to] += ans[cur];
                ans[to] %= md;  //�������
            }
        } 
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << endl;
    }
    

    system("pause");
    return 0;
}