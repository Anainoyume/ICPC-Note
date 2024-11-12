#include <bits/stdc++.h>
using namespace std;

/* 
    ��ͨĪ���㷨, ��һ���������������ѯ���⡣
    ��һ�ֱ��������������Ǹ��ӶȽϺ�Ϊ O(sqrt(n))
    ˼���Ǵ���һ�����䱩��ת�Ƶ���һ�����䣬�кܶ�Ĳ���Ҫ�ظ�����Ĳ���
    ��������һ���������ת��˳�򣬻����̶���Ӱ���㷨�����ܡ�
    �������÷ֿ�˼�룬����ʹ�ø��Ӷ�Ϊ O(sqrt(n))
 */

using i64 = long long;
const i64 maxN = 1e5+5;

i64 a[maxN], id[maxN], ans[maxN];
i64 l = 1, r = 0, res; // ��ס l �� 1 ��ʼ

struct Q {
    i64 l, r, k;
} q[maxN];

// Ī�ӻ������, ֻ��Ҫ���� Add �� Sub �������ʵ��

void Add(i64 x) {

}

void Sub(i64 x) {

}

int main()
{   
    // ����n, ��ѯ����m
    int n, m;
    cin >> n >> m;

    // ���� + �ֿ�
    i64 siz = sqrt(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        id[i] = i / siz;
    }

    // �����ѯ
    for (int i = 0; i < m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].k = i;
    }

    // ����
    sort(q,q+m,[](Q x, Q y) -> bool {
        // ��ͨ�ֿ�����
        // return id[x.l] == id[y.l] ? x.r < y.r : id[x.l] < id[y.l];
        
        // ��ż���������������ܸ���
        if(id[x.l] != id[y.l]) return x.l < y.l;
        return (id[x.l] & 1) ? x.r < y.r : x.r > y.r;
    });

    // ����ת��
    for (int i = 0; i < m; ++i) {
        // ����ȴ��� r ���� �����
        /*
            ��Щ��Ҫ��֤������ʱ�� l <= r��
            �����ƶ��˵�ͳ�ƴ𰸻����������Ī��Ҫ�Ȱ� r ���Ƶ����������
        */
        while (q[i].l < l) Add(--l);
        while (q[i].r > r) Add(++r);
        while (q[i].l > l) Sub(l++);
        while (q[i].r < r) Sub(r--);
        ans[q[i].k] = res;
    }

    // �����
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << endl;
    }
}   