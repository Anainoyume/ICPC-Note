#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5+10;
/* 
    这一题是一道 LIS on tree
    树上最长上升子序列

    我们可以使用DFS，每次遍历每一条单独的路径，每条单独的路径
    我们都可以使用 线性LIS 来求解。
    回溯的时候，我们把做过的修改还原即可。
 */
bool vis[maxN];
int cnt[maxN];
int sta[maxN];  //维护单调栈
int nodes[maxN];
vector<int> edges[maxN];
  
//dfs进行每条路线上的LIS
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
