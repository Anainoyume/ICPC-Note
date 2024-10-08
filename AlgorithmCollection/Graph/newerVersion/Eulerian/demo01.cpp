#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+5;

// Hierholzer算法 (逐步插入回路法) 复杂度 O(n+m)
// 如果需要输出字典序最小的欧拉路或欧拉回路的话，因为需要将边排序
// 地图着色问题：如何用最少的颜色给地图上的所有区域着色，使得相邻区域颜色不同？


bool edges[maxN][maxN];
// 我们用邻接表访问边的时候是有顺序的，为了记录我们上一次访问到哪条边了，我们可以使用 st 来记录上一次访问到的
// 最后一条边，加快我们的查询速度
int deg[maxN], st[maxN];
int n, m;

int node[maxN]; //点的值

stack<int> ans;
void Hierholzer(int cur)
{
    for (int i = 1; i <= n; i++) {
        if (edges[cur][i]) {
            edges[cur][i] = false;
            edges[i][cur] = false;
            Hierholzer(i);
        }
    }
    ans.push(node[cur]);
}

void print() {
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}


signed main()
{
    // 先计算所有点的入度
    // 奇点数为 2 的时候指定 奇点 为起点，为 0 时，任意指定起点

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i];
    }

    for (int i = 1; i <= m; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from][to] = true;
        edges[to][from] = true;

        deg[from] += 1;
        deg[to] += 1;
    }

    int deg1 = 0, bg = -1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] & 1) {
            bg = i;
            deg1 += 1;
        }
    }

    // 不存在欧拉回路
    if (deg1 != 0 && deg1 != 2) {
        cout << -1 << endl;
    }

    if (deg1 == 0) {
        // 只有偶数点
        Hierholzer(1);
        print();
    }
    else { 
        //存在两个奇点
        Hierholzer(bg);
        print();
    }


    system("pause");
    return 0;
}