#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)    //左孩子
#define rs(x) ((x) << 1|1)  //右孩子
const int maxN=2e5+10;

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

void modify(int l, int r, int k, int x = 1) {
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
        if(l <= mid) modify(l,r,k,ls(x));
        if(r > mid) modify(l,r,k,rs(x));
        pushup(x);//最后别忘了pushup一下
    }
}


signed main(){
    // 数据直接输入到 全局 arr 数组里
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    build(1,n);

    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y, k;
            cin >> x >> y >> k;
            modify(x,y,k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query(x,y) << endl;
        }
    }

    system("pause");
    return 0;
}
