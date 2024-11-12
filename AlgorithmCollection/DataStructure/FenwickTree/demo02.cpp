//��״����
/* 
    �������⣺
    ����һ�����飬Ҫ����֧�ֵ����޸ĺ�����͵Ĳ���

    �����ȿ��Ǳ����ⷨ��
    �����޸ĺܼ� nums[i] = k; ���� O(1)
    ��������ǿ���ʹ��forѭ���ۼӣ����Ǹ��Ӷ�Ϊ O(n)
    �����ݺܳ���ʱ����ȻЧ�ʵ���

    ���ǿ���ʹ����״����������������

    ǰ��֪ʶ��
    lowbit() ����

    lowbit��ʾһ�����������ִ����һ��1��ʼ�Լ����������е�0��ɵ���ֵ
    ���磺(b��ʾbin,������)
    lowbit(44) -> lowbit(101100b) -> 100b -> 4

    �����ֵ�����ǿ��Խ�0...101100ȡ��
    �õ� 1...010011
    �����ټ�1 �õ� 1...010100

    ���ǽ��бȶԣ�
    0...101_100
    1...010_100
    ���Կ�����������100���������෴
    ʹ�ð�λ�룬���ɻ��lowbit��ֵ

    lowbit(n) = n & (~n+1)
    ���Ƕ�֪�� ~n+1 = -n
    ���
    lowbit(n) = n & (-n)

    ����һ������
    8 6 1 4 5 5 1 1 3 2 1 4 9 0 7 4

    ����ʹ����״����
    arr[n]����״����ĳ��Ⱥ�numsһ��
    arr�ĵ�i��Ԫ�ش���һ����0��ʼ������Ϊlowbit(i)�������
    ���ң�����arr[i]�����ĸ����Ϊarr[i+lowbit(i)]
    ���������Ϸ����Ϊarr[i-lowbit(i)]

    ע�⣺�����iΪ�±�+1 ������
    �±��1��ʼ��

    ����
    ��������飬����״����Ϊ
    �±꣺ 1   2   3   4   5   6    7   8   9   10  11   12   13   14   15   16
          8   14   1   19  5  10   1   31  3    5   1   10   9    9    7    61
 */
#include <bits/stdc++.h>
using namespace std;

//��lowBit����
struct Fenwick
{
    int size;
    vector<int> arr;

    // ע���±�� 1 ��ʼ
    void init(int n) {
        size = n;
        arr.resize(n+1,0);
    }

    inline int lowBit(int num) {
        return num & (-num);
    }

    //�����޸�
    void update(int index, int value) {
        for (int i = index; i <= size; i += lowBit(i))
            arr[i] += value;
    }

    //��ǰn���
    int sum(int n) {
        int ans = 0;
        //��i��ʱ���ܽ���һ�����㣬֮��Ͳ����ˣ�i=1��ʱ��Ϊ��С
        for (int i = n; i; i -= lowBit(i))
            ans += arr[i];
        //nΪ0��ʱ�򷵻�0, arr�ĵ�0λҲΪ0
        return ans;
    }

    //�������
    int sum(int left, int right) {
        return sum(right) - sum(left-1);
    }
};

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n;
    int cur = 0;

    Fenwick tr(n);

    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        tr.update(i,cur);
    }
    
    cin >> m;
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        cout << tr.sum(l,r) << endl;
    }
    

    system("pause");
    return 0;
}
