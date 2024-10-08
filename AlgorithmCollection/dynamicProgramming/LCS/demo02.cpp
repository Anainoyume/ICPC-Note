/* 
    �������У�����Ԫ����ͬ��������λ�ò�ͬ������
    �����и��� LCS ת��Ϊ LIS ������

    ������
    5 1 2 4 3
    5 2 3 4 1

    ���Ƕ�
    5 1 2 4 3 ����һ�����Ϊ a b c d e

    ���ն�Ӧ��ϵ���θı�arr2�����Ԫ��Ϊ
    a c e d b

    ����arr1�����Ժ�һ����֤Ϊ����
    ��ô������arr2�����ȡһ�������������У�����һ����arr1��������

    ��ô���������Ԫ�Ժ�� arr2 �� LIS �Ϳ�����

    ʵ�ʲ�����ʱ��
    5 1 2 4 3 ��Ӧ 1 2 3 4 5 ���±�ţ�ͨ�����ӳ���ϵ
    ���Ǹı�arr2��ֵ������ʹ�ù�ϣ��������
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
int n, k;
int arr[maxN];
int mp[maxN];
int sta[maxN];

int main(int argc, char const *argv[])
{
    cin >> n;
    int cur{};
    for (int i = 1; i <= n; i++)
    {
        cin >> cur;
        mp[cur] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = mp[arr[i]];
    }

    for (int i = 0; i < n; i++)
    {
        if (k == 0 || sta[k-1] < arr[i]) {
            sta[k++] = arr[i];
        }
        else {
            int p = lower_bound(sta,sta+k,arr[i])-sta;
            sta[p] = arr[i];
        }
    }
    
    cout << k << endl;
    
    system("pause");
    return 0;
}
