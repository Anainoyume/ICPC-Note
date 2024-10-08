#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)     // ����
#define rs(x) ((x) << 1 | 1) // �Һ���
const int maxN = 1e5 + 5;

int md = 1e9 + 7;

struct Node
{
    int sum;  // �����
    int l, r; // �߽�
};

Node tree[maxN * 4]; // �߶���Ҫ���ı��ռ�Ŷ

int arr[maxN]; // ԭ����

inline void pushup(int x)
{
    tree[x].sum = (tree[ls(x)].sum * tree[rs(x)].sum) % md; // pushup����
}

void build(int l, int r, int x = 1)
{
    // ��������
    tree[x].l = l;
    tree[x].r = r;

    if (l == r)
    {
        tree[x].sum = arr[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(l, mid, ls(x));
    build(mid + 1, r, rs(x));
    pushup(x);
}

int query(int l, int r, int x = 1)
{
    if (l <= tree[x].l && r >= tree[x].r)
        return tree[x].sum % md;

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 1;

    if (l <= mid)
        sum = (sum * query(l, r, ls(x))) % md;
    if (r > mid)
        sum = (sum * query(l, r, rs(x))) % md;
    return sum;
}

// �����޸�
void change(int index, int var, int x = 1)
{
    int l = tree[x].l, r = tree[x].r;
    int mid = l + (r - l >> 1);

    if (r < index || l > index)
        return;

    if (l == r)
    {
        if (l == index)
            tree[x].sum = var;
        return;
    }

    change(index, var, ls(x));
    change(index, var, rs(x));
    pushup(x);
}

void solve()
{
    int n;
    cin >> n >> md;

    for (int i = 1; i <= n; ++i)
    {
        arr[i] = 1;
    }

    memset(tree, 0, sizeof(tree));

    build(1, n);

    for (int i = 1; i <= n; ++i)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int m;
            cin >> m;
            change(i, m);
            cout << query(1, n) % md << endl;
        }
        else
        {
            int pos;
            cin >> pos;
            change(pos, 1);
            cout << query(1, n) % md << endl;
        }
    }
}

signed main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        solve();
    }

    system("pause");
    return 0;
}
