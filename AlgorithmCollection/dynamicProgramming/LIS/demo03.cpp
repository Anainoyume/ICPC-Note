#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+10;
/* 
    ��һ����һ�� LIS on tree
    ���������������

    ���ǿ���ʹ��DFS��ÿ�α���ÿһ��������·����ÿ��������·��
    ���Ƕ�����ʹ�� ����LIS ����⡣
    ���ݵ�ʱ�����ǰ��������޸Ļ�ԭ���ɡ�
 */
bool vis[maxN];
int cnt[maxN];
int sta[maxN];  //ά������ջ
int nodes[maxN];
vector<int> edges[maxN];
  
//dfs����ÿ��·���ϵ�LIS
void dfs(int cur, int k) {
    // cout << cur << ": " << endl;
    // for (int i = 0; i < k; i++)
    //     cout << sta[i] << " ";
    // cout << endl;

    vis[cur] = true;
    cnt[cur] = (k == 0) ? 1 : (nodes[cur] > sta[k-1] ? k+1 : k);
    
    if (k == 0 || nodes[cur] > sta[k-1]) {
        sta[k] = nodes[cur];
        for (auto &&to : edges[cur]) {
            if (!vis[to]) dfs(to,k+1);             
        }
    }
    else {
        int i = lower_bound(sta,sta+k,nodes[cur])-sta;
        int last = sta[i];
        sta[i] = nodes[cur];
        for (auto &&to : edges[cur]) {
            if (!vis[to]) dfs(to,k);
        }
        sta[i] = last;
    }
}

int main(int argc, char const *argv[])
{
    int n{};
    cin >> n;
    
    int cur{};
    for (int i = 2; i <= n; i++)
    {
        cin >> cur;
        edges[i].push_back(cur);
        edges[cur].push_back(i);
    }

    for (int i = 1; i <= n; i++)
        cin >> nodes[i];
    
    sta[0] = nodes[0];
    dfs(1,0);
    for (int i = 2; i <= n; i++)
    {
        cout << cnt[i] << " ";
    }
    cout << endl;
    
    

    system("pause");
    return 0;
}
