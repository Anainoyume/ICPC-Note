/* 
    树链剖分 (重链剖分 O(logn))
    使用场景：
    
    1. 一棵树上 x 到 y 路径都加上 z
    2. 求路径 x 到 y 结点值之和
    3. 给结点 x 所有子树结点值都加上 z
    4. 求 x 为根的子树内 所有结点值之和
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
/*****************************************线段树代码********************************************/
#define ls(x) ((x) << 1)    //左孩子
#define rs(x) ((x) << 1|1)  //右孩子
const int maxM = 1e5+5;

struct Node {
    int sum; // 区间和
    int l,r; // 边界
    int tag; // lazyTag
};

Node tree[maxM*4]; //线段树要开四倍空间哦

int w[maxM]; //原数列, 树链剖分，按照dfs序以后的那个数组

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

void build(int l, int r, int x = 1){
    //建树操作
    tree[x].l = l;
    tree[x].r = r;
    tree[x].tag = 0;
    
    if(l == r){
        tree[x].sum = w[l];
        return;
    }

    int mid = l + ((r - l) >> 1);
    build(l,mid,ls(x));
    build(mid+1,r,rs(x));
    pushup(x);
}

int query(int l, int r, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) 
        return tree[x].sum;

    pushdown(x); //注意，区间查询时也要下懒传标记

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 0;

    if(l <= mid) sum += query(l,r,ls(x));
    if(r > mid) sum += query(l,r,rs(x));
    return sum; 
}

void update(int l, int r, int k, int x = 1){
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
/*********************************************************************************************/

const int maxN = 1e5+5;

vector<int> edges[maxN];

int weight[maxN];       //结点的权值
int pa[maxN];           //父节点
int deep[maxN];         //点的深度
int son[maxN];          //重儿子结点
int siz[maxN];          //记录子树大小
int top[maxN];          //当前链的头结点
int dfn[maxN], tim;    //时间戳 和 时间戳计数器
//int w[maxN];            //按照dfs序排列的结点权值 (放在上面了)
//  外加一个维护 w 数组的线段树

// 第一次 dfs
void dfs1(int cur, int parent) {
    pa[cur] = parent;
    deep[cur] = deep[parent] + 1;
    siz[cur] = 1;
    int maxsize = -1;
    for (auto&& to : edges[cur]) {
        if (to == parent)   
            continue;
        dfs1(to,cur);
        siz[cur] += siz[to];
        if (siz[to] > maxsize) {
            maxsize = siz[to];
            son[cur] = to;        // 记录重儿子
        } 
    }
}

// 第二次dfs
void dfs2(int cur, int head) {
    dfn[cur] = ++tim;   //计数
    top[cur] = head;
    w[tim] = weight[cur];   //存储
    if (!son[cur])
        return;
    dfs2(son[cur],head);    // 优先走重儿子
    for (auto&& to : edges[cur]) {  //走剩下的结点
        if (to == pa[cur] || to == son[cur])    // 跳过父节点和已经走过的重儿子结点
            continue;
        dfs2(to,to);    //划分一条新链，head为 to 自己
    }
}

// 将以 x 为根节点的 子树 节点值都加上 k
inline void modifys(int x, int k) {
    // dfn + siz 是因为根结点与其子数的 dfn 序是连续的
    update(dfn[x], dfn[x] + siz[x] - 1, k);
}

// 查询以 x 为根结点的 子数权值之和
inline int querys(int x) {
    return query(dfn[x], dfn[x] + siz[x] - 1);
}

// 修改树上从 x 到 y 加上 k 值
void modifyChain(int x, int y, int k) {
    // 如果不在同一条重链上
    while (top[x] != top[y]) {
        // 优先走深度大的
        if (deep[top[x]] < deep[top[y]]) 
            swap(x, y);
        update(dfn[top[x]],dfn[x],k);  //先将一条重链上修改，注意父节点的 dfn一定更小
        x = pa[top[x]];
    }
    //如果在同一条重链上
    if (deep[x] > deep[y])
        swap(x, y);
    update(dfn[x],dfn[y],k);
}

// 查询，基本和修改相同
int queryChain(int x, int y) {
    int res = 0;
    while (top[x] != top[y]) {
        if (deep[top[x]] < deep[top[y]]) 
            swap(x, y);
        res += query(dfn[top[x]],dfn[x]);
        x = pa[top[x]];
    }
    if (deep[x] > deep[y])
        swap(x, y);
    res += query(dfn[x],dfn[y]);
    return res;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    // n个点, m个查询

    // 输入权重
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }

    for (int i = 1; i <= n-1; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    
    int r = 1;  //根节点
    dfs1(r,r);
    dfs2(r,r);
    build(1,n);

    // 重链剖分 logn 线段树 logn 查询 m 次，总 mlog?n 复杂度
    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, a;
            cin >> x >> a;
            update(dfn[x],dfn[x],a);    //注意单点修改的位置！！！！
        }
        else if (op == 2) {
            int x, a;
            cin >> x >> a;
            modifys(x,a);
        }
        else {
            int x;
            cin >> x;
            cout << queryChain(1,x) << endl;
        }
    }


    system("pause");
    return 0;
}