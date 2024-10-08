#include <bits/stdc++.h>
using namespace std;

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
// 每次维护点到根距离时现将当前点deep设置为1，接入并查集，调用find
int deep[maxN];
int find(int x) {
    if (pa[x] != x) {
        int t = find(pa[x]);
        deep[x] += deep[pa[x]];
        pa[x] = t;
    }
    return pa[x];
}

signed main()
{


    system("pause");
    return 0;
}