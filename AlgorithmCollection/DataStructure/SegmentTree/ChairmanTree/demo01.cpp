#include <bits/stdc++.h>
using namespace std;

/* 
    主席树
 */

// 离散化
vector<int> v;
inline int getid(int x) {
    return lower_bound(v.begin(),v.end(),x) - v.begin()+1;
}

const int maxN = 2e5+5;

struct Node
{
    int ls, rs, sum;
} tree[maxN * 40];
int tot, root[maxN];

// 插入左区间，右区间，上一个版本线段树编号，当前线段树编号，插入的值
void insert(int l, int r, int pre, int& x, int p) {
    tree[++tot] = tree[pre];    // 先复制一份前缀的结点，我们可以在此基础上修改，这样就借用了那些 "不动" 的结点，我们只修改变化的
    x = tot;                    // 将编号指向结点的位置
    tree[x].sum += 1;           // 由于插入了一个新的数字，所以 sum 肯定 +1
    if (l == r) return;
    int mid = l + (r - l >> 1);

    if (p <= mid) // 接下来判断这个数在区间的哪个位置，递归插入
        insert(l, mid, tree[pre].ls, tree[x].ls, p);
    else 
        insert(mid+1, r, tree[pre].rs, tree[x].rs, p);
}

// 查询
int query(int l, int r, int Lx, int Rx, int k) {
    if (l == r) return l;   // 叶子结点，说明已经找到了
    int mid = l + (r - l >> 1);
    int tempSum = tree[tree[Rx].ls].sum - tree[tree[Lx].ls].sum;    // 我们要将两个版本的前缀线段树进行做差处理，导出区间线段树的值

    if (k <= tempSum) 
        // 左子树的 tempSum 表示在 [l ~ mid] 这个范围内，存在tempSum个数，如果 k <= tempSum, 就说明第 k 小肯定在 [l ~ mid]
        return query(l, mid, tree[Lx].ls, tree[Rx].ls, k);
    else 
        // 否则肯定在右子树里，但此时我们在右子树里找的就不是第 k 小了，而是第 k-tempSum 小
        // 比如当前tempSum = 2, 我们的 k = 3，左区间范围 2 个数，我们整个区间的第3小，那说明就找右区间第 1 小的数
        return query(mid+1, r, tree[Lx].rs, tree[Rx].rs, k-tempSum);
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end()); //离散化去重

    // 插入
    for (int i = 1; i <= n; ++i) {
        insert(1,n,root[i-1],root[i],getid(a[i]));
    }

    //询问
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        // 查询离散化对应原值
        cout << v[query(1,n,root[l-1],root[r],k)-1] << endl;
    }

    system("pause");
    return 0;
}