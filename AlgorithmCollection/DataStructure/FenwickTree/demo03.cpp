/* 
    �������޸ĺ������ѯ����״����
 */
#include <bits/stdc++.h>
using namespace std;

struct Fenwick 
{
    // ԭ���� �� �������1, 2
    vector<int> arr, d1, d2;
    size_t size;

    inline int lowbit(int x) {
        return x & (-x);
    }
    
    // �±�� 1 ��ʼ
    void init(size_t n) {
        arr.resize(n+1,0);
        d1.resize(n+2,0);
        d2.resize(n+2,0);
        size = n;
    }

    // �߼���״����
    // �� d �������޸�
    // ��ʼ���������
    void initDarr() {
        d1[1] = d2[1] = arr[1];
        for (int i = 2; i <= size; ++i) {
            d1[i] = arr[i] - arr[i-1];
            d2[i] = i * (arr[i] - arr[i-1]);
        }
    }

    // �Բ�����������
    void add(int index, int value){ 
        for (int i = index; i <= size; i += lowbit(i))
            d1[i] += value, d2[i] += value * index;
    }

    //������[l, r]����x
    void range_add(int left, int right, int value){ 
        add(left, value), add(right + 1, -value);
    }

    // ǰ׺��ѯ
    int sum(int index) {
        int res = 0;
        for(int i = index; i; i -= lowbit(i))
            res += (index + 1) * d1[i] - d2[i];
        return res;
    }

    // ����Ͳ�ѯ
    int sum(int left, int right) {
        return sum(right) - sum(left - 1);
    }

};

signed main()
{
    Fenwick tr;
    tr.init(10);

    cout << tr.sum(1,10) << endl;
    tr.range_add(2,5,2);
    tr.range_add(6,6,3);
    cout << tr.sum(1,10) << endl;

    system("pause");
    return 0;
}