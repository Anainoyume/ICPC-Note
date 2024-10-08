/* 
    ���۷ֿ�

    floor(a/(bc)) == floor(floor(a/b)/c)

    ���۷ֿ���ۣ�
    ʹ floor(n/i) == floor(n/j)
    �������� i <= j <= n �� j ֵΪ floor(n/floor(n/i))��
    ��ֵ floor(n/i) ���ڵĿ���Ҷ˵�Ϊ floor(n/floor(n/i))
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//       n
//����   �� floor(n/i)
//      i=1

//����ʹ�����۷ֿ����Ż�
ll f(ll N, ll k) {
    ll n = N;
    if (n > k)
        n = k;
    ll left = 1;   //һ��ʼ�������߽�Ϊleft
    ll ans = 0;
    while (left <= n) {
        ll right = min(k / (k / left),n);   //ȡ��Сֵ����Ϊ n����С�� k
        ans += ((left+right)*(right-left+1)/2) * (k / left); //��ֵͬ*���䳤��(���亯��)
        left = right + 1;   //��߽�����
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //ceil�컨��-����ȡ��  floor�ذ�-����ȡ��
    //cout << ceil(5.3) << " " << floor(5.3) << endl;

    //C++�ĳ����Դ���һ������ȡ��

    ll n = 0;
    ll k = 0;

    // k % i = k - (k/i)*i;
    //��������� (k/i)*i �ĺͣ��������ÿ��������۷ֿ�
    cin >> n >> k;  //n���ܱ�kС
    
    cout << n*k - f(n,k) << endl;

    //system("pause");
    return 0;
}

