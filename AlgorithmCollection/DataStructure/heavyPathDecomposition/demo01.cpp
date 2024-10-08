/* 
    �����ʷ� (�����ʷ� O(logn))
    ʹ�ó�����
    
    1. һ������ x �� y ·�������� z
    2. ��·�� x �� y ���ֵ֮��
    3. ����� x �����������ֵ������ z
    4. �� x Ϊ���������� ���н��ֵ֮��
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
/*****************************************�߶�������********************************************/
#define ls(x) ((x) << 1)    //����
#define rs(x) ((x) << 1|1)  //�Һ���
const int maxM = 1e5+5;

struct Node {
    int sum; // �����
    int l,r; // �߽�
    int tag; // lazyTag
};

Node tree[maxM*4]; //�߶���Ҫ���ı��ռ�Ŷ

int w[maxM]; //ԭ����, �����ʷ֣�����dfs���Ժ���Ǹ�����

inline void pushup(int x) {
    tree[x].sum = tree[ls(x)].sum + tree[rs(x)].sum; //pushup����
}

inline void pushdown(int x) {
    if (tree[x].tag){
        //�������ڵ����������
        tree[ls(x)].tag += tree[x].tag;
        tree[rs(x)].tag += tree[x].tag;

        //������ڵ������Ǹ����������ӽڵ�
        tree[ls(x)].sum += tree[x].tag * (tree[ls(x)].r - tree[ls(x)].l + 1);
        tree[rs(x)].sum += tree[x].tag * (tree[rs(x)].r - tree[rs(x)].l + 1);

        tree[x].tag = 0;
        //�������������ڵ�������
    }
}

void build(int l, int r, int x = 1){
    //��������
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

    pushdown(x); //ע�⣬�����ѯʱҲҪ���������

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 0;

    if(l <= mid) sum += query(l,r,ls(x));
    if(r > mid) sum += query(l,r,rs(x));
    return sum; 
}

void update(int l, int r, int k, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) {
        //����鵽��������
        tree[x].sum += k * (tree[x].r - tree[x].l + 1);   //���޸��������
        tree[x].tag += k;                               //Ȼ��������������
        //ע������һ��Ҫ����˳�����޸ģ��ٱ�ǣ�
    }
    else{
        //�����Ҫ�������²�ѯ
        pushdown(x);  //�Ȱ���������´�
        int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
        //������������ѯ
        if(l <= mid) update(l,r,k,ls(x));
        if(r > mid) update(l,r,k,rs(x));
        pushup(x);//��������pushupһ��
    }
}
/*********************************************************************************************/

const int maxN = 1e5+5;

vector<int> edges[maxN];

int weight[maxN];       //����Ȩֵ
int pa[maxN];           //���ڵ�
int deep[maxN];         //������
int son[maxN];          //�ض��ӽ��
int siz[maxN];          //��¼������С
int top[maxN];          //��ǰ����ͷ���
int dfn[maxN], tim;    //ʱ��� �� ʱ���������
//int w[maxN];            //����dfs�����еĽ��Ȩֵ (����������)
//  ���һ��ά�� w ������߶���

// ��һ�� dfs
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
            son[cur] = to;        // ��¼�ض���
        } 
    }
}

// �ڶ���dfs
void dfs2(int cur, int head) {
    dfn[cur] = ++tim;   //����
    top[cur] = head;
    w[tim] = weight[cur];   //�洢
    if (!son[cur])
        return;
    dfs2(son[cur],head);    // �������ض���
    for (auto&& to : edges[cur]) {  //��ʣ�µĽ��
        if (to == pa[cur] || to == son[cur])    // �������ڵ���Ѿ��߹����ض��ӽ��
            continue;
        dfs2(to,to);    //����һ��������headΪ to �Լ�
    }
}

// ���� x Ϊ���ڵ�� ���� �ڵ�ֵ������ k
inline void modifys(int x, int k) {
    // dfn + siz ����Ϊ��������������� dfn ����������
    update(dfn[x], dfn[x] + siz[x] - 1, k);
}

// ��ѯ�� x Ϊ������ ����Ȩֵ֮��
inline int querys(int x) {
    return query(dfn[x], dfn[x] + siz[x] - 1);
}

// �޸����ϴ� x �� y ���� k ֵ
void modifyChain(int x, int y, int k) {
    // �������ͬһ��������
    while (top[x] != top[y]) {
        // ��������ȴ��
        if (deep[top[x]] < deep[top[y]]) 
            swap(x, y);
        update(dfn[top[x]],dfn[x],k);  //�Ƚ�һ���������޸ģ�ע�⸸�ڵ�� dfnһ����С
        x = pa[top[x]];
    }
    //�����ͬһ��������
    if (deep[x] > deep[y])
        swap(x, y);
    update(dfn[x],dfn[y],k);
}

// ��ѯ���������޸���ͬ
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
    // n����, m����ѯ

    // ����Ȩ��
    for (int i = 1; i <= n; ++i) {
        cin >> weight[i];
    }

    for (int i = 1; i <= n-1; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
        edges[to].push_back(from);
    }
    
    
    int r = 1;  //���ڵ�
    dfs1(r,r);
    dfs2(r,r);
    build(1,n);

    // �����ʷ� logn �߶��� logn ��ѯ m �Σ��� mlog?n ���Ӷ�
    for (int i = 1; i <= m; ++i) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, a;
            cin >> x >> a;
            update(dfn[x],dfn[x],a);    //ע�ⵥ���޸ĵ�λ�ã�������
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