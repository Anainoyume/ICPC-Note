/* 
    Ford_Fulkerson�㷨�����¼��FF�㷨
    ���Ӷȼ��ߣ���˽���ѧϰ�ο���
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int maxN = 1e4+5;
int n, m, s, t; //nΪ������mΪ������sΪԴ�㣬tΪ���

struct Edge
{
    //�յ㣬�����������
    int to, cap, rev;
    Edge(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {}
};
vector<Edge> edges[maxN];
bool vis[maxN]; //��ʾ�ߵķ���, ��dfsѰ��·��ʱʹ��

void addEdge(int from, int to, int cap) {
    //����ʹ��vector���мӱߵ�һ�������ɣ�ʹ��vectorд�������㷨���鷳������Ѱ�ҷ���ߣ����������ǿ�����������
    //from����ķ����to����to�У�ǡ���ǵ��±�Ϊedges[to].size()Ҫ�������Ԫ��
    edges[from].push_back(Edge(to,cap,edges[to].size()));
    //ͬ��from������һ��,edges[from].size()����1�������ټ�һ��1�����õ�����������Ҫ�ķ�����±�
    //ע�ⷴ���һ��ʼ��capҪΪ0
    edges[to].push_back(Edge(from,0,edges[from].size()-1));
}

int dfs(int cur, int minflow) {
    if (cur == t) {
        return minflow; //�ҵ����յ㣬����minflow
    }
    vis[cur] = true;

    for (int i = 0; i < edges[cur].size(); ++i) {
        auto [to, cap, rev] = edges[cur][i];
        // vis��ֹ�ظ�������ѭ���� cap > 0 Ҫ���Ǳ��Ƴ��ı�
        if (!vis[to] && cap > 0) {
            int d = dfs(to,min(minflow,cap));
            // �ӵײ�dfs�������d != 0 ��˵���ҵ��˻��t
            if (d > 0) {
                edges[cur][i].cap -= d; //��ǰ�߼�ȥd������
                edges[to][rev].cap += d;    //����߼���d������
                return d;
            }
        }
    }

    //���һ�в��������ܽ��У�����û�б��ˣ�˵��û���ҵ����t
    return 0;   //����0��ʾʧ��״̬
}


signed main()
{
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++)
    {
        int from, to, cap;
        cin >> from >> to >> cap;
        addEdge(from,to,cap);
    }
    
    int flow = 0, f = 1;
    while (f = dfs(s,INT64_MAX)) {
        fill(vis,vis+maxN,false);
        flow += f;
    }
    cout << flow << endl;

    system("pause");
    return 0;
}