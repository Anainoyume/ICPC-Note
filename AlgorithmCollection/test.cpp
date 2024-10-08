#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

const int maxn = 1e6 + 5;

int n, m;
int a[maxn];

struct segment_tree
{
    ll sum[maxn << 2];
    int mx[maxn << 2], se[maxn << 2];
    int tag[maxn << 2], cnt[maxn << 2];

    void update(int p)
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
        mx[p] = max(mx[p << 1], mx[p << 1 | 1]);
        cnt[p] = (mx[p] == mx[p << 1]) * cnt[p << 1];
        cnt[p] += (mx[p] == mx[p << 1 | 1]) * cnt[p << 1 | 1];
        if (mx[p] == mx[p << 1])
            se[p] = se[p << 1];
        else
            se[p] = mx[p << 1];
        if (mx[p] == mx[p << 1 | 1])
            se[p] = max(se[p], se[p << 1 | 1]);
        else
            se[p] = max(se[p], mx[p << 1 | 1]);
    }

    void build(int p, int l, int r)
    {
        tag[p] = -1;
        if (l == r)
        {
            sum[p] = mx[p] = a[l];
            se[p] = -1, cnt[p] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1, mid + 1, r);
        update(p);
    }

    void solve(int p, int limit)
    {
        if (mx[p] <= limit)
            return;
        if (se[p] < limit && limit < mx[p])
        {
            sum[p] -= 1ll * (mx[p] - limit) * cnt[p];
            mx[p] = limit, tag[p] = limit;
            return;
        }
        solve(p << 1, limit), solve(p << 1 | 1, limit);
        update(p);
    }

    void push_down(int p)
    {
        if (~tag[p])
        {
            solve(p << 1, tag[p]);
            solve(p << 1 | 1, tag[p]);
            tag[p] = -1;
        }
    }

    void Min(int p, int l, int r, int L, int R, int v)
    {
        if (L <= l && r <= R)
        {
            solve(p, v);
            return;
        }
        int mid = (l + r) >> 1;
        push_down(p);
        if (L <= mid)
            Min(p << 1, l, mid, L, R, v);
        if (R > mid)
            Min(p << 1 | 1, mid + 1, r, L, R, v);
        update(p);
    }

    int queryMx(int p, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return mx[p];
        int mid = (l + r) >> 1, res = 0;
        push_down(p);
        if (L <= mid)
            res = max(res, queryMx(p << 1, l, mid, L, R));
        if (R > mid)
            res = max(res, queryMx(p << 1 | 1, mid + 1, r, L, R));
        return res;
    }

    ll querySum(int p, int l, int r, int L, int R)
    {
        if (L <= l && r <= R)
            return sum[p];
        int mid = (l + r) >> 1;
        ll res = 0;
        push_down(p);
        if (L <= mid)
            res += querySum(p << 1, l, mid, L, R);
        if (R > mid)
            res += querySum(p << 1 | 1, mid + 1, r, L, R);
        return res;
    }
} T;

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int Test;
    cin >> Test;
    while (Test--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        T.build(1, 1, n);
        for (int i = 1; i <= m; i++)
        {
            int opt, l, r;
            cin >> opt >> l >> r;
            if (!opt)
            {
                int v{};
                cin >> v;
                T.Min(1, 1, n, l, r, v);
            }
            if (opt == 1)
                printf("%d\n", T.queryMx(1, 1, n, l, r));
            if (opt == 2)
                printf("%lld\n", T.querySum(1, 1, n, l, r));
        }
    }
    return 0;
}
