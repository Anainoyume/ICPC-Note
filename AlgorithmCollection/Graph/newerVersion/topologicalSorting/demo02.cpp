#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int maxN = 1e3+5;
/* 
    dfs 进行拓扑排序
 */

struct Edge
{
    int to, weight;
};

int inDeg[maxN];
vector<Edge> edges[maxN];

// -1 以处理， 0 未处理， 1 处理中
int vis[maxN];

stack<int> ans;

bool topoSort(int cur) {
    vis[cur] = 1;
    for (auto&& [to, weight] : edges[cur]) {
        if (vis[to] == 1)   //后继比前驱先访问，说明存在环
            return false;
        if (!vis[to] && !topoSort(to)) 
            return false;
    }

    ans.push(cur);
    vis[cur] = -1;
    return true;
}

int main()
{
    int n = 0;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int from = i+1;
        int to = 1;
        while (to) {
            cin >> to;
            if (to == 0) break;
            edges[from].push_back({to,1});
            //inDeg[to] += 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) 
            topoSort(i);   //注意，vis == 0 才进行
    }
    
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;

    system("pause");
    return 0;
}