#include <bits/stdc++.h>
using namespace std;

/* 
    ��ϯ��
 */

// ��ɢ��
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

// ���������䣬�����䣬��һ���汾�߶�����ţ���ǰ�߶�����ţ������ֵ
void insert(int l, int r, int pre, int& x, int p) {
    tree[++tot] = tree[pre];    // �ȸ���һ��ǰ׺�Ľ�㣬���ǿ����ڴ˻������޸ģ������ͽ�������Щ "����" �Ľ�㣬����ֻ�޸ı仯��
    x = tot;                    // �����ָ�����λ��
    tree[x].sum += 1;           // ���ڲ�����һ���µ����֣����� sum �϶� +1
    if (l == r) return;
    int mid = l + (r - l >> 1);

    if (p <= mid) // �������ж��������������ĸ�λ�ã��ݹ����
        insert(l, mid, tree[pre].ls, tree[x].ls, p);
    else 
        insert(mid+1, r, tree[pre].rs, tree[x].rs, p);
}

// ��ѯ
int query(int l, int r, int Lx, int Rx, int k) {
    if (l == r) return l;   // Ҷ�ӽ�㣬˵���Ѿ��ҵ���
    int mid = l + (r - l >> 1);
    int tempSum = tree[tree[Rx].ls].sum - tree[tree[Lx].ls].sum;    // ����Ҫ�������汾��ǰ׺�߶���������������������߶�����ֵ

    if (k <= tempSum) 
        // �������� tempSum ��ʾ�� [l ~ mid] �����Χ�ڣ�����tempSum��������� k <= tempSum, ��˵���� k С�϶��� [l ~ mid]
        return query(l, mid, tree[Lx].ls, tree[Rx].ls, k);
    else 
        // ����϶��������������ʱ���������������ҵľͲ��ǵ� k С�ˣ����ǵ� k-tempSum С
        // ���統ǰtempSum = 2, ���ǵ� k = 3�������䷶Χ 2 ������������������ĵ�3С����˵������������� 1 С����
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
    v.erase(unique(v.begin(),v.end()),v.end()); //��ɢ��ȥ��

    // ����
    for (int i = 1; i <= n; ++i) {
        insert(1,n,root[i-1],root[i],getid(a[i]));
    }

    //ѯ��
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;
        // ��ѯ��ɢ����Ӧԭֵ
        cout << v[query(1,n,root[l-1],root[r],k)-1] << endl;
    }

    system("pause");
    return 0;
}