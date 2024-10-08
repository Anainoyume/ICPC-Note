## K元上升子序列
定义 $dp[i][j]$ 表示，到 $j$ 个位置为止的 $i$ 元上升子序列个数。
那么显然有转移方程 $dp[i][j] = \sum_{k<i,a[k]<a[i]}{dp[i-1][k]}$, 这个复杂度是 $O(N^2K)$ 的，显然不能接受。
注意到我们可以利用权值线段树 (树状数组也可以)，将 $dp[i][j]$ 的值，存在下标为 $a[j]$ 的位置，这样就可以使用 `query` 快速求出符合条件的求和了。
指的注意的是我们每一元都需要开一个新的树，因此在进行 `query` 的时候，需要新插入上一元相应位置的 $dp$ 值。

ps. $a[i]$ 过于大时，视 $n$ 的大小进行离散化。

$k = 3$ 时，代码如下：

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)    //左孩子
#define rs(x) ((x) << 1|1)  //右孩子
const int maxN=1e5+10;

struct Node {
    int sum; // 区间和
    int l,r; // 边界
    int tag; // lazyTag
} tree[maxN*4]; //线段树要开四倍空间哦

int arr[maxN]; //原数列

inline void pushup(int x) {
    tree[x].sum = tree[ls(x)].sum + tree[rs(x)].sum; //pushup操作
}

inline void pushdown(int x) {
    if (tree[x].tag){
        //如果这个节点上有懒标记
        tree[ls(x)].tag += tree[x].tag;
        tree[rs(x)].tag += tree[x].tag;

        //把这个节点的懒标记给他的两个子节点
        tree[ls(x)].sum += tree[x].tag * (tree[ls(x)].r - tree[ls(x)].l + 1);
        tree[rs(x)].sum += tree[x].tag * (tree[rs(x)].r - tree[rs(x)].l + 1);

        tree[x].tag = 0;
        //别忘了清空这个节点的懒标记
    }
}

void build(int l, int r, int x = 1) {
    //建树操作
    tree[x].l = l;
    tree[x].r = r;
    tree[x].tag = 0;
    
    if(l == r){
        tree[x].sum = arr[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(l,mid,ls(x));
    build(mid+1,r,rs(x));
    pushup(x);
}

int query(int l, int r, int x = 1) {
    if(l <= tree[x].l && r >= tree[x].r) 
        return tree[x].sum;

    pushdown(x); //注意，区间查询时也要下懒传标记

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 0;

    if(l <= mid) sum += query(l,r,ls(x));
    if(r > mid) sum += query(l,r,rs(x));
    return sum; 
}

void update(int l, int r, int k, int x = 1) {
    if(l <= tree[x].l && r >= tree[x].r) {
        //如果查到子区间了
        tree[x].sum += k * (tree[x].r - tree[x].l + 1);   //先修改这个区间
        tree[x].tag += k;                               //然后给它打上懒标记
        //注：这里一定要分清顺序，先修改，再标记！
    }
    else{
        //如果需要继续向下查询
        pushdown(x);  //先把懒标记向下传
        int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
        //这里很像区间查询
        if(l <= mid) update(l,r,k,ls(x));
        if(r > mid) update(l,r,k,rs(x));
        pushup(x);//最后别忘了pushup一下
    }
}


signed main(){
    // 数据直接输入到 全局 arr 数组里
    int n, m;
    cin >> n;
    vector<int> arr(n+1);
    int N = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        N = max(N, arr[i]);
    }

    int dp[4][n+1]{};
    for (int i = 1; i <= n; ++i) {
        dp[1][i] = 1;
    }

    for (int i = 2; i <= 3; ++i) {
        build(1,N);
        for (int j = 1; j <= n; ++j) {
            update(arr[j],arr[j],dp[i-1][j]);
            dp[i][j] += query(1,arr[j]-1);
        }
    }

    int ans{};
    for (int i = 1; i <= n; ++i) {
        ans += dp[3][i];
    }
    
    cout << ans << endl;


    system("pause");
    return 0;
}
```