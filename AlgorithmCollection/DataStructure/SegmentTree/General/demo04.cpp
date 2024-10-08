#include <bits/stdc++.h>
using namespace std;
/* 
    ��˾���߶����򵥰汾
    ά�� 3 ��������
    1.  0 l r t, ������ [l, r] ���� ai = min(ai, t);
    2.  1 l r,   ������� [l, r] �����ֵ
    3.  2 l r,   �������� 
 */

#define endl '\n'

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1|1)
#define mid(l,r) ((l) + ((r) - (l) >> 1)) 

const int maxN = 1e6+5;
int arr[maxN];

struct Node {
    int64_t sum;
    int left, right;
    int mx, se, tag, cnt;
} tree[maxN << 2];

void pushup(int x) {
    // sum �� mx �ĸ��£��߼��Ƚϼ򵥾Ͳ�������
    tree[x].sum = tree[ls(x)].sum + tree[rs(x)].sum;
    tree[x].mx = max(tree[ls(x)].mx, tree[rs(x)].mx);

    // ���ֵ�����ĸ���
    tree[x].cnt = (tree[x].mx == tree[ls(x)].mx) * tree[ls(x)].cnt;
    tree[x].cnt += (tree[x].mx == tree[rs(x)].mx) * tree[rs(x)].cnt;

    // ����������������ֵ��ͬ����δ�ֵ�ȵ�����������Ĵδ�ֵ���������������������ֵ
    if (tree[x].mx == tree[ls(x)].mx) tree[x].se = tree[ls(x)].se;
    else tree[x].se = tree[ls(x)].mx;

    // ͬ���ٺ���������ȡ���ֵ�Ƚ�һ��
    if (tree[x].mx == tree[rs(x)].mx) tree[x].se = max(tree[x].se, tree[rs(x)].se);
    else tree[x].se = max(tree[x].se, tree[rs(x)].mx);
}

void build(int l, int r, int x = 1) {
    tree[x].left = l;
    tree[x].right = r;
    tree[x].tag = -1;

    if (l == r) {
        tree[x].sum = tree[x].mx = arr[l];
        tree[x].se = -1, tree[x].cnt = 1;
        return;
    }

    int mid{mid(l,r)};
    build(l, mid, ls(x));
    build(mid+1, r, rs(x));
    pushup(x);
}


void pushdown_solve(int x, int limit) {
    if (tree[x].mx <= limit)
        return;
    if (tree[x].se < limit && limit < tree[x].mx) {
        tree[x].sum -= 1ll * (tree[x].mx - limit) * tree[x].cnt;
        tree[x].mx = limit;
        tree[x].tag = limit;
        return;
    }
    pushdown_solve(ls(x), limit);
    pushdown_solve(rs(x), limit);
    pushup(x);
}

void pushdown(int x) {
    // ~x, ֻ�� x == -1 �Ż�Ϊ false, �����ж� tag ����ֵ�����, �� tag Ҳ�п���Ϊ 0
    if (~tree[x].tag) {
        pushdown_solve(ls(x), tree[x].tag);
        pushdown_solve(rs(x), tree[x].tag);
        tree[x].tag = -1;
    }
}

void modify_min(int l, int r, int v, int x = 1) {
    if (l <= tree[x].left && tree[x].right <= r) {
        pushdown_solve(x, v);
        return;
    }

    int mid{mid(tree[x].left,tree[x].right)};
    pushdown(x);

    if (l <= mid) modify_min(l, r, v, ls(x));
    if (r > mid) modify_min(l, r, v, rs(x));
    pushup(x);
}

int query_max(int l, int r, int x = 1) {
    if (l <= tree[x].left && tree[x].right <= r)
        return tree[x].mx;
    
    int mid{mid(tree[x].left,tree[x].right)};
    int res{};
    pushdown(x);

    if (l <= mid) res = max(res, query_max(l, r, ls(x)));
    if (r > mid) res = max(res, query_max(l, r, rs(x)));
    return res;
}

int64_t query_sum(int l, int r, int x = 1) {
    if (l <= tree[x].left && tree[x].right <= r)
        return tree[x].sum;
    
    int mid{mid(tree[x].left,tree[x].right)};
    int64_t res{};
    pushdown(x);

    if (l <= mid) res += query_sum(l, r, ls(x));
    if (r > mid) res += query_sum(l, r, rs(x));
    return res;
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t{};
    cin >> t;
    while (t--) {
        
        int n{}, m{};
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            cin >> arr[i];
        }

        build(1, n);

        while (m--) {
            int op, l, r, v;
            cin >> op >> l >> r;
            if (op == 0) {
                cin >> v; modify_min(l,r,v);
            }
            else if (op == 1) {
                cout << query_max(l,r) << endl;
            }
            else {
                cout << query_sum(l,r) << endl;
            }
        }
    }

    system("pause");
    return 0;
}