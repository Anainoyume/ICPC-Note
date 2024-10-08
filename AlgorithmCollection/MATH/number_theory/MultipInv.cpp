#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
/*
    ��������������ַ�������˷���Ԫ
    ���� ab = 1 mod m��
    ���Ǹ�������ѧ����֪ʶ��֪����˵�� ab mod m = 1 mod m = t
    ���� ab = km + t,  1 = sm + t
    ���� ab-1  = (k-s)m
    ��������õ� ab + (s-k)m = 1
    ��������Ҫ�� a �ĳ˷���Ԫ b�����Ǽ��� b Ϊ x�� ���� s-k Ϊ y
    �������Ǿ����ˣ�
    ax + my = 1
    a,m ��֪������д�� a,b����ʽ

    ��ô���� ax + by = 1

    ��ô����������Ȼ����ʹ�� ��չŷ�Ｘ���㷨���
 */
// 1. ��չŷ�Ｘ���㷨
int exgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return d;
}

int FindInv(int a, int m) {
    int x{}, y{};
    int d = exgcd(a,m,x,y);
    if (d == 1)
        return x < 0 ? x + m : x;   //ע����������xС��0������Ҫ����1��m
    else
        return -1;
}


// 2. When p is Prime and gcd(a,p) is equal to 1�����÷���С����
/* 
    ����֪������С����
    a^{p-1} = 1 mod p

    ��ô a * a^{p-2} = 1 mod p

    ��Ȼ��������£� a^{p-2} ���� a �� �˷���Ԫ
    ����ʹ�ô�ģ�����������
 */
i64 fastPow(i64 a, i64 n, i64 m) {
    i64 ans{1};
    while (n) {
        if (n&1) ans = (ans*a) % m;
        a = (a*a) % m;
        n >>= 1;
    }
    return ans;
}


//3. ��������Ԫ
/* 
    ��ʱ�����ݹ�ģ���Ƚϴ�������Ҫ�� 1~n �����Ը�Ԫ�ص���Ԫ
    �����и���ķ�����(��һư��ʾ��Ԫ)

    ���� p = ki + r
    ��ô ki + r = 0 mod p
    ki (i'r') + r (i'r') = 0 mod p
    kr' + i' = 0 mod p
    i' = -kr' mod p
    i' = -(p/i)r' mod p

    ����Ϊ k = p/i ; r = p%i

    i' = -(p/i)*(p%i)' mod p

    ��ô��������֪�� (p%i)'���Ϳ��Եó� i'
    ����һ������ʽ��
 */
vector<i64> linearInv(i64 n, i64 p) {
    vector<i64> inv(n,0);
    inv[1] = 1;

    for (i64 i = 2; i <= n; i++) {
        // -(p/i) �� % p ��������� +p ,��ֹ���ָ�����Ԫ
        inv[i] = (p - p/i) * inv[p % i] % p;
    }
    return inv;
}

int main()
{

    i64 n{}, p{};
    cin >> n >> p;

    //�����������ʱ����endl������\n�ɹ�
    auto inv = linearInv(n,p);

    cout << 1 * inv[3] % p << endl;

    system("pause");
    return 0;
}