/* 
    n ��λ��
    m ����

    ÿ 2 ����֮��Ҫ�������� 1 ����λ�������п��ܵ���ֲ����

    ��շ���

    ���ó� m ���������ǻ�ʣ n-m ��λ��

    ���ǽ� �����������Լ���λ�� ���뵽ʣ�µ� n-m λ��֮��ļ����ȥ�������Ϳ��Ա����������һ���ˡ�
    ���������ڱ�ţ�ʹ�����С���Ҫע�� n-m �ļ������ n-m+1 ����������Ϊ����ϻ��� 1 ����λ����û��������������

    �𰸣�A[n-m+1][m] = c[n-m+1][m] * fac[m]

    �������ⷶΧ�����޷�Ԥ�������������ô����ֻ��ʹ�� �������� ��һ���Դ������ǵ�ֵ��
    ʹ�����е���ʽ��

    A[m][n] = A[m-1][n] + n*A[m-1][n-1];

    �����򵥵��ǣ����ڣ�
    A[m][n] = n! / (m-n)! = (m-n+1)*(m-n+2)* ... *m
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int index, pos, tree, mod;
    cin >> index >> pos >> tree >> mod;

    int ans{1};
    for (int i = pos-2*tree+2; i <= pos-tree+1; ++i) {
        ans = (ans % mod * (i % mod)) % mod;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}