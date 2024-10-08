## KԪ����������
���� $dp[i][j]$ ��ʾ���� $j$ ��λ��Ϊֹ�� $i$ Ԫ���������и�����
��ô��Ȼ��ת�Ʒ��� $dp[i][j] = \sum_{k<i,a[k]<a[i]}{dp[i-1][k]}$, ������Ӷ��� $O(N^2K)$ �ģ���Ȼ���ܽ��ܡ�
ע�⵽���ǿ�������Ȩֵ�߶��� (��״����Ҳ����)���� $dp[i][j]$ ��ֵ�������±�Ϊ $a[j]$ ��λ�ã������Ϳ���ʹ�� `query` ���������������������ˡ�
ָ��ע���������ÿһԪ����Ҫ��һ���µ���������ڽ��� `query` ��ʱ����Ҫ�²�����һԪ��Ӧλ�õ� $dp$ ֵ��

ps. $a[i]$ ���ڴ�ʱ���� $n$ �Ĵ�С������ɢ����

$k = 3$ ʱ���������£�

```cpp
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ls(x) ((x) << 1)    //����
#define rs(x) ((x) << 1|1)  //�Һ���
const int maxN=1e5+10;

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

void update(int l, int r, int k, int x = 1) {
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


signed main(){
    // ����ֱ�����뵽 ȫ�� arr ������
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