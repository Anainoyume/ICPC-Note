#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define endl '\n'
const i64 m = 1e9+7;

/* 
    �׳�����Ԫ
    �����Ѿ�֪��3������Ԫ�ķ�������������������һ�½׳���Ԫ�����Ƕ��� fac[i] Ϊ i!
    ifac[i] Ϊ (i!)' Ҳ���� fac[i] ����Ԫ

    ���ǿ�����

    ifac[i]*fac[i] = 1 mod m

    ifac[i]*fac[i-1]*i = 1 mod m

    (ifac[i]*i) * fac[i-1] = 1 mod m

    ��Ȼ ifac[i-1] = ifac[i] * i

    ��ô����ֻ��Ҫ����� fac[n]��Ȼ��ʹ����չŷ�Ｘ�ã����߿����ݣ���� ifac[n]��
    �������Ե��Ƴ����е� ifac[i] �ͺ���
 */

template<typename T = i64>
T fastPow(T a, T n, T m) {
    T ans{1};
    while (n) {
        if (n&1) ans = (ans*a) % m;
        a = (a*a) % m;
        n >>= 1;
    }
    return ans;
}

int main()
{
    i64 n{};
    cin >> n;

    i64 fac[n+1]{}, ifac[n+1]{};

    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = i*fac[i-1] % m;
    }

    ifac[n] = fastPow(fac[n],m-2,m);
    for (int i = n-1; i >= 1; i--) {
        ifac[i] = ifac[i+1]*(i+1) % m;  
    }

    for (int i = 1; i <= n; i++) {
        cout << fac[i]*ifac[i] % m << endl;
    }
    
    

    system("pause");
    return 0;
}