/* 
    支持赋值操作的线段树
 */
#include <bits/stdc++.h>
using namespace std;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1|1)
#define mid(l,r) ((l) + ((r) - (l) >> 1))

const int maxN = 20;

struct Node {
    int left, right, sum, tag;
} tree[maxN << 2];

int arr[maxN];

void pushup(int x) {
    tree[x].sum = tree[ls(x)].sum + tree[rs(x)].sum;
}

void build(int l, int r, int x = 1) {
    tree[x].left = l;
    tree[x].right = r;
    tree[x].tag = -1;   //我们允许赋值为 0
    if (l == r) {
        tree[x].sum = arr[l];
        return;
    }
    int mid{mid(l,r)};
    build(l, mid, ls(x));
    build(mid+1, r, rs(x));
    pushup(x);
}

void pushdown(int x) {
    if (~tree[x].tag) {
        tree[ls(x)].sum = tree[x].tag * (tree[ls(x)].right - tree[ls(x)].left + 1);
        tree[rs(x)].sum = tree[x].tag * (tree[rs(x)].right - tree[rs(x)].left + 1);

        tree[ls(x)].tag = tree[x].tag;
        tree[rs(x)].tag = tree[x].tag;

        tree[x].tag = -1;
    }
}

void modify(int l, int r, int v, int x = 1) {
    if (l <= tree[x].left && tree[x].right <= r) {
        tree[x].sum = v * (tree[x].right - tree[x].left + 1);
        tree[x].tag = v;
        return;
    }
    pushdown(x);
    int mid{(mid(tree[x].left,tree[x].right))};
    if (l <= mid) modify(l, r, v, ls(x));
    if (r > mid) modify(l, r, v, rs(x));
    pushup(x);
}

int query(int l, int r, int x = 1) {
    if (l <= tree[x].left && tree[x].right <= r) {
        return tree[x].sum;
    }
    pushdown(x);
    int mid{(mid(tree[x].left,tree[x].right))};
    int res{};
    if (l <= mid) res += query(l, r, ls(x));
    if (r > mid) res += query(l, r, rs(x));
    return res;
}

signed main()
{
    for (auto&& i : views::iota(1,11)) {
        arr[i] = i;
    }

    build(1,10);

    cout << query(1,10) << " " << query(1,5) << endl;

    modify(1,3,9);

    modify(5,6,7);

    modify(3,8,10);

    cout << query(1,10) << endl;


    system("pause");
    return 0;
}