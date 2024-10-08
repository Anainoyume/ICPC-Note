#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+1;
int n, m; 
int dfn[maxN], low[maxN], inde, res;
// dfn：记录每个点的时间戳
// low：能不经过父亲到达最小的编号
//inde：时间戳
//res：答案数量

bool vis[maxN], flag[maxN]; // flag: 答案 vis：标记是否重复
vector<int> edges[maxN];       // 存图用的

void Tarjan(int cur, int father) {                             
    vis[cur] = true;            
    low[cur] = dfn[cur] = ++inde; 

    int child = 0;    

    for (auto&& to : edges[cur]) { 
        if (!vis[to]) {
            child += 1; 

            Tarjan(to, cur);     

            low[cur] = min(low[cur], low[to]); 

            if (father != cur && low[to] >= dfn[cur] && !flag[cur]) { 
                flag[cur] = true;
                res += 1; 
            }
        }
        else if (to != father) {
            low[cur] = min(low[cur], dfn[to]);
        }
    }
    
    if (father == cur && child >= 2 && !flag[cur]) {
        flag[cur] = true;
        res++;
    }
}

int main()
{
    cin >> n >> m; 

    for (int i = 1; i <= m; i++)
    { 
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    } 

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            inde = 0;     
            Tarjan(i, i); 
        }
    }

    cout << res << endl;

    for (int i = 1; i <= n; i++) {
        if (flag[i])
            cout << i << " ";
    }

    system("pause"); 
    return 0;
}