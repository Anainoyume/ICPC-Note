#include <bits/stdc++.h>
using namespace std;

/* 
    普通莫队算法, 在一个序列里解决区间查询问题。
    是一种暴力的做法，但是复杂度较好为 O(sqrt(n))
    思想是从上一个区间暴力转移到下一个区间，有很多的不需要重复计算的部分
    但是这样一来，区间的转移顺序，会最大程度上影响算法的形能。
    我们利用分块思想，可以使得复杂度为 O(sqrt(n))
 */

using i64 = long long;
const i64 maxN = 1e5+5;

i64 a[maxN], id[maxN], ans[maxN];
i64 l = 1, r = 0, res; // 记住 l 从 1 开始

struct Q {
    i64 l, r, k;
} q[maxN];

// 莫队基本框架, 只需要考虑 Add 和 Sub 函数如何实现

void Add(i64 x) {

}

void Sub(i64 x) {

}

int main()
{   
    // 长度n, 查询个数m
    int n, m;
    cin >> n >> m;

    // 输入 + 分块
    i64 siz = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i / siz;
    }

    // 处理查询
    for (int i = 0; i < m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].k = i;
    }

    // 排序
    sort(q,q+m,[](Q x, Q y) -> bool {
        // 普通分块排序
        // return id[x.l] == id[y.l] ? x.r < y.r : id[x.l] < id[y.l];
        
        // 奇偶波浪排序，疑似性能更优
        if(id[x.l] != id[y.l]) return x.l < y.l;
        return (id[x.l] & 1) ? x.r < y.r : x.r > y.r;
    });

    // 区间转移
    for (int i = 0; i < m; ++i) {
        // 最好先处理 r 右移 的情况
        /*
            有些题要保证在任意时刻 l <= r，
            否则移动端点统计答案会出锅，所以莫队要先把 r 右移的情况处理了
        */
        while (q[i].l < l) Add(--l);
        while (q[i].r > r) Add(++r);
        while (q[i].l > l) Sub(l++);
        while (q[i].r < r) Sub(r--);
        ans[q[i].k] = res;
    }

    // 输出答案
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
}   