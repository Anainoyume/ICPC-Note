#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const int maxN = 1e4 + 5;

int pa[maxN];    //并查集

int Find(int x) {
    return pa[x] == x ? x : pa[x] = Find(pa[x]);
}

// x 合并到 y 上
void Union(int x, int y) {
    pa[Find(x)] = Find(y);
}

bool Search(int x, int y) {
    return Find(x) == Find(y);
}

// 维护点到根距离的 带权并查集
int deep[maxN];
int find(int x) {
    if (pa[x] != x) {
        int t = find(pa[x]);
        deep[x] += deep[pa[x]];
        pa[x] = t;
    }
    return pa[x];
}

struct Edge {
    int from, to, weight;  
    
    bool operator<(const Edge& other) const {
        return weight > other.weight;
    }  
};

vector<Edge> edges[maxN];

signed main()
{
    int n, m;
    cin >> n >> m;

    priority_queue<Edge> que;

    for (int i = 0; i < m; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        Edge e = {from,to,weight};
        edges[from].push_back(e);
        que.push(e);
    }

    for (int i = 1; i <= n; i++) {
        pa[i] = i;
    }
    
    
    int ans = 0, cnt = 0;
    // Kruskal算法
    while (!que.empty()) {
        auto [from, to, weight] = que.top();
        if (Search(from,to)) {  
            //环
            que.pop();
            continue;
        }
        else {
            cnt += 1;
            ans += weight;
            
            Union(from,to);
            que.pop();
        }

        if (cnt == n-1)
            break;
    }

    if (cnt == n-1) {
        cout << ans << endl;
    }
    else {
        cout << "orz" << endl;
    }

    system("pause");
    return 0;
}