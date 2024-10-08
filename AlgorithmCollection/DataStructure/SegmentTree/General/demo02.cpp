/* 
    �߶���ά���ӷ��ͳ˷�
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)    //����
#define rs(x) ((x) << 1|1)  //�Һ���
const int maxN=1e5+10;

int md = 1e9+7;

struct Node {
    int sum; // �����
    int l,r; // �߽�
    int addtag, multag; // lazyTag
};

Node tree[maxN*4]; //�߶���Ҫ���ı��ռ�Ŷ

int arr[maxN]; //ԭ����

inline void pushup(int x) {
    tree[x].sum = (tree[ls(x)].sum + tree[rs(x)].sum) % md; //pushup����
}

inline void pushdown(int x) {
    // ����
    int lsLen = tree[ls(x)].r - tree[ls(x)].l + 1;
    tree[ls(x)].sum = (tree[ls(x)].sum * tree[x].multag + tree[x].addtag * lsLen) % md;
    tree[ls(x)].multag = (tree[ls(x)].multag * tree[x].multag) % md;
    tree[ls(x)].addtag = (tree[ls(x)].addtag * tree[x].multag + tree[x].addtag) % md;

    // �Һ���
    int rsLen = tree[rs(x)].r - tree[rs(x)].l + 1;
    tree[rs(x)].sum = (tree[rs(x)].sum * tree[x].multag + tree[x].addtag * rsLen) % md;
    tree[rs(x)].multag = (tree[rs(x)].multag * tree[x].multag) % md;
    tree[rs(x)].addtag = (tree[rs(x)].addtag * tree[x].multag + tree[x].addtag) % md;
        
    // ����
    tree[x].addtag = 0;
    tree[x].multag = 1;
}

void build(int l, int r, int x = 1){
    //��������
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

    pushdown(x); //ע�⣬�����ѯʱҲҪ���������

    int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
    int sum = 0;

    if(l <= mid) sum = (sum + query(l,r,ls(x))) % md;
    if(r > mid) sum = (sum + query(l,r,rs(x))) % md;
    return sum; 
}

void add(int l, int r, int k, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) {
        //����鵽��������
        tree[x].sum = (tree[x].sum + k * (tree[x].r - tree[x].l + 1)) % md;   //���޸��������
        tree[x].addtag = (tree[x].addtag + k) % md;                               //Ȼ��������������
        //ע������һ��Ҫ����˳�����޸ģ��ٱ�ǣ�
    }
    else{
        //�����Ҫ�������²�ѯ
        pushdown(x);  //�Ȱ���������´�
        int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
        //������������ѯ
        if(l <= mid) add(l,r,k,ls(x));
        if(r > mid) add(l,r,k,rs(x));
        pushup(x);//��������pushupһ��
    }
}

void mult(int l, int r, int k, int x = 1){
    if(l <= tree[x].l && r >= tree[x].r) {
        //����鵽��������
        tree[x].sum = (tree[x].sum * k) % md;   //���޸��������
        tree[x].multag = (tree[x].multag * k) % md;   //Ȼ��������������
        tree[x].addtag = (tree[x].addtag * k) % md;
        //ע������һ��Ҫ����˳�����޸ģ��ٱ�ǣ�
    }
    else{
        //�����Ҫ�������²�ѯ
        pushdown(x);  //�Ȱ���������´�
        int mid = tree[x].l + ((tree[x].r - tree[x].l) >> 1);
        //������������ѯ
        if(l <= mid) mult(l,r,k,ls(x));
        if(r > mid) mult(l,r,k,rs(x));
        pushup(x);//��������pushupһ��
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
