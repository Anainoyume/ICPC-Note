/* 
    线段树维护加法和乘法
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)    //左孩子
#define rs(x) ((x) << 1|1)  //右孩子
const int maxN=1e5+10;

int md = 1e9+7;

struct Node {
    int sum; // 区间和
    int l,r; // 边界
    int addtag, multag; // lazyTag
};

Node tree[maxN*4]; //线段树要开四倍空间哦

int arr[maxN]; //原数列

inline void pushup(int x) {
    tree[x].sum = (tree[ls(x)].sum + tree[rs(x)].sum) % md; //pushup操作
}

inline void pushdown(int x) {
    // 左孩子
    int lsLen = tree[ls(x)].r - tree[ls(x)].l + 1;
    tree[ls(x)].sum = (tree[ls(x)].sum * tree[x].multag + tree[x].addtag * lsLen) % md;
    tree[ls(x)].multag = (tree[ls(x)].multag * tree[x].multag) % md;
    tree[ls(x)].addtag = (tree[ls(x)].addtag * tree[x].multag + tree[x].addtag) % md;

    // 右孩子
    int rsLen = tree[rs(x)].r - tree[rs(x)].l + 1;
    tree[rs(x)].sum = (tree[rs(x)].sum * tree[x].multag + tree[x].addtag * rsLen) % md;
    tree[rs(x)].multag = (tree[rs(x)].multag * tree[x].multag) % md;
    tree[rs(x)].addtag = (tree[rs(x)].addtag * tree[x].multag + tree[x].addtag) % md;
        
    // 重置
    tree[x].addtag = 0;
    tree[x].multag = 1;
}

void build(int l, int r, int x = 1){
    //建树操作
    tree[x].l = l;
    tree[x].r = r;
    tree[x].addtag = 0;
    tree[x].multag = 1;
    
    if(l == r){
        tree[x].sum = arr[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(l,mid,ls(x));
    build(mid+1,r,rs(x));
    pushup(x);
}

int query(int l, int r, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) 
        return tree[x].sum % md;

    pushdown(x); //注意，区间查询时也要下懒传标记

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 0;

    if(l <= mid) sum = (sum + query(l,r,ls(x))) % md;
    if(r > mid) sum = (sum + query(l,r,rs(x))) % md;
    return sum; 
}

void add(int l, int r, int k, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) {
        //如果查到子区间了
        tree[x].sum = (tree[x].sum + k * (tree[x].r - tree[x].l + 1)) % md;   //先修改这个区间
        tree[x].addtag = (tree[x].addtag + k) % md;                               //然后给它打上懒标记
        //注：这里一定要分清顺序，先修改，再标记！
    }
    else{
        //如果需要继续向下查询
        pushdown(x);  //先把懒标记向下传
        int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
        //这里很像区间查询
        if(l <= mid) add(l,r,k,ls(x));
        if(r > mid) add(l,r,k,rs(x));
        pushup(x);//最后别忘了pushup一下
    }
}

void mult(int l, int r, int k, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) {
        //如果查到子区间了
        tree[x].sum = (tree[x].sum * k) % md;   //先修改这个区间
        tree[x].multag = (tree[x].multag * k) % md;   //然后给它打上懒标记
        tree[x].addtag = (tree[x].addtag * k) % md;
        //注：这里一定要分清顺序，先修改，再标记！
    }
    else{
        //如果需要继续向下查询
        pushdown(x);  //先把懒标记向下传
        int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
        //这里很像区间查询
        if(l <= mid) mult(l,r,k,ls(x));
        if(r > mid) mult(l,r,k,rs(x));
        pushup(x);//最后别忘了pushup一下
    }
}

signed main(){

    int n, m;
    cin >> n >> m >> md;
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
            mult(x,y,k);
        }
        else if (op == 2) {
            int x, y, k;
            cin >> x >> y >> k;
            add(x,y,k);
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
