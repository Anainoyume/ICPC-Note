/* 
    n <= 10^5
    ������������� a^2 + b^2 = c^2 ����
    a <= b <= c

    ��ͨɨ��϶��޷�ͨ��

    ���ǿ���ʽ�ӱ���
    a^2 = (c-b)(b+c);

    ������ c-b = x;  c+b = y;

    c = (x+y)/2;
    b = (y-x)/2;    ���ǹ۲쵽�����b,c��Ϊ��������ôx,y����ż��һ����ͬ

    ���ҿ�������x��y��Ȼ��a^2������

    ��ô�ͺ�˵�ˣ�
    ����ֱ�����a^2���е�����

    a^2 ������������ô��
    ��Ȼ a���Էֽ�
    a = p1p2p3p4p5.... (����ûдָ��)
    a^2 ��Ȼ��ֻ�ǰ�a���������ӵ�ָ�����Զ�

    ��ξ�ȷһ�����ֵ�ÿһ�������أ�
    1.�Ƚ��������ӷֽ�
    2.��ʹ������ö��ÿһ������
    ����: 100 = 2^2*5^2
    2 5
    ָ����0��ʼ����
    2*1 = 2
    1*5 = 5
    2*2*1 = 4
    1*5*5 = 25
    2*5 = 10
    2*2*5 = 20
    2*5*5 = 50

    ���������е�������ö��x

    y = a^2/x
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int n;
int prime[100010];
int vis[100010];

void factor(int num) {
    for (int i = 2; i <= sqrt(num); ++i) {
        while (num % i == 0) {
            cout << i << " ";
            num /= i;
        }
    }
}

signed main()
{
    cin >> n;
    factor(4);
    

    system("pause");
    return 0;
}