#include <bits/stdc++.h>
using namespace std;
/* 
    ����������
    6
    1 2 3 4 3 5
    3
    1 2
    3 5
    2 6
 */
//arrΪά������״���飬aΪԭ���飬p[x]��ʾԪ��x������a�����һ�γ��ֵ�λ�õ��±꣬ansΪ������
//nΪa����Ԫ�ظ�����mΪ��ѯ����
int arr[500005], a[500005], p[1000005], ans[200005];
int n, m;

//��lowBit����
int lowBit(int num) {
    return num & (-num);
}

//�����޸�
void add(int index, int value) {
    for (int i = index; i <= n; i += lowBit(i))
        arr[i] += value;
}

//��ǰn���
int query(int n) {
    int ans = 0;
    //��i��ʱ���ܽ���һ�����㣬֮��Ͳ����ˣ�i=1��ʱ��Ϊ��С
    for (int i = n; i; i -= lowBit(i))
        ans += arr[i];
    //nΪ0��ʱ�򷵻�0, arr�ĵ�0λҲΪ0
    return ans;
}

struct ask  //��ѯ�ṹ��
{
    int l, r, id;
} q[200005];
// q Ϊ��ѯ�ṹ������

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }

    //�����еĲ�ѯ�������Ҷ˵��С��������
    sort(q + 1, q + 1 + m, [&](const ask a, const ask b){
        return a.r < b.r; 
    });

    // r ����׷������ a ��Ԫ�صĵ�ǰ����λ��
    int r = 0;
    for (int i = 1; i <= m; ++i)    //���α���ÿ����ѯ
    {
        while (r < q[i].r)
        {
            ++r;
            add(r, 1);

            if (p[a[r]])    //����Ѿ��鵽��
                add(p[a[r]], -1);

            p[a[r]] = r;    //���������ֵ��±�
        }

        ans[q[i].id] = query(r) - query(q[i].l - 1);
    }

    for (int i = 1; i <= m; ++i)
        cout << ans[i] << endl;

    system("pause");
    return 0;
}
