#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

/*
    �ֿ��������

    ����鳤Ϊ s
    ���ڿ��ڵĲ�ѯ���������㣬����Ӷ�Ϊ s
    ���ڿ��Ĳ�ѯ�����߱������㣬�м�ʹ�ÿ���ͣ�����Ӷ�Ϊ n/s + s
    �ɻ�������ʽ��֪���� s = sqrt(n) ʱ�����Ӷ����ţ�Ϊ O(sqrt(n))
 */

int id[50005], len;
// id ��ʾ��ı��, len=sqrt(n) , ����������е�s, sqrt��ʱ��ʱ�临�Ӷ�����
i64 a[50005], b[50005], s[50005];

// a �����ʾ��������, b �����¼ÿ��������帳ֵ���, ������ lazy_tag, s
// ��ʾ����Ԫ���ܺ�
void add(int l, int r, i64 x) { // ����ӷ�
    int sid = id[l], eid = id[r];

    if (sid == eid) { // ��һ������
        for (int i = l; i <= r; i++)
            a[i] += x, s[sid] += x;
        return;
    }

    for (int i = l; id[i] == sid; i++)
        a[i] += x, s[sid] += x;

    for (int i = sid + 1; i < eid; i++)
        b[i] += x, s[i] += len * x; // �������������(�����Ŀ�)

    for (int i = r; id[i] == eid; i--)
        a[i] += x, s[eid] += x;
    // �������в������Ŀ�ֱ�Ӽ����,��OK
}

i64 query(int l, int r, i64 p) { // �����ѯ
    int sid = id[l], eid = id[r];
    i64 ans = 0;

    if (sid == eid) { // ��һ������ֱ�ӱ������
        for (int i = l; i <= r; i++)
            ans = (ans + a[i] + b[sid]) % p;
        return ans;
    }

    for (int i = l; id[i] == sid; i++)
        ans = (ans + a[i] + b[sid]) % p;

    for (int i = sid + 1; i < eid; i++)
        ans = (ans + s[i]) % p;

    for (int i = r; id[i] == eid; i--)
        ans = (ans + a[i] + b[eid]) % p;
    // ������������޸���һ������
    return ans;
}

int main()
{
    int n;
    cin >> n;
    len = sqrt(n); // ��ֵ����ʽ��֪���Ӷ�����Ϊ����n

    for (int i = 1; i <= n; i++) { // ����Ҫ��
        cin >> a[i];
        id[i] = (i - 1) / len + 1;  // �ֿ���
        s[id[i]] += a[i];
    }

    for (int i = 1; i <= n; i++) {
        int op, l, r, c;
        cin >> op >> l >> r >> c;
        if (op == 0)
            add(l, r, c);
        else
            cout << query(l, r, c + 1) << endl;
    }

    return 0;
}