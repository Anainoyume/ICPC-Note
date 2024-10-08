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

//       n
//����   �� floor(n/i)
//      i=1

int sum[10010];

//����ʹ�����۷ֿ����Ż�
int f(int n) {
    int left = 1;   //һ��ʼ�������߽�Ϊleft
    int ans = 0;
    while (left <= n) {
        int right = n / (n / left); //����Ҷ˵�
        ans += (sum[right] - sum[left-1]) * (n / left); //��ֵͬ*���䳤��(���亯��)
        left = right + 1;   //��߽�����
    }
    return ans;
}

int main()
{
    //ceil�컨��-����ȡ��  floor�ذ�-����ȡ��
    //cout << ceil(5.3) << " " << floor(5.3) << endl;

    //C++�ĳ����Դ���һ������ȡ��

    int n = 0;
    int k = 0;

    // k % i = k - (k/i)*i;
    //��������� (k/i)*i �ĺͣ��������ÿ��������۷ֿ�
    cin >> n >> k;
    sum[1] = 1;
    for (int i = 2; i <= k; i++)
    {
        sum[i] = sum[i-1] + i;  //��ʼ����
    }
    

    cout << k*k - f(k) + (n-k)*k << endl;

    system("pause");
    return 0;
}

