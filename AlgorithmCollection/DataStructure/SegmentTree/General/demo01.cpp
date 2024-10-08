#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)    //����
#define rs(x) ((x) << 1|1)  //�Һ���
const int maxN=2e5+10;

struct Node {
    int sum; // �����
    int l,r; // �߽�
    int tag; // lazyTag
} tree[maxN*4]; //�߶���Ҫ���ı��ռ�Ŷ

int arr[maxN]; //ԭ����

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

void build(int l, int r, int x = 1) {
    //��������
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

    pushdown(x); //ע�⣬�����ѯʱҲҪ���������

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 0;

    if(l <= mid) sum += query(l,r,ls(x));
    if(r > mid) sum += query(l,r,rs(x));
    return sum; 
}

void modify(int l, int r, int k, int x = 1) {
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
        if(l <= mid) modify(l,r,k,ls(x));
        if(r > mid) modify(l,r,k,rs(x));
        pushup(x);//��������pushupһ��
    }
}


signed main(){
    // ����ֱ�����뵽 ȫ�� arr ������
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
