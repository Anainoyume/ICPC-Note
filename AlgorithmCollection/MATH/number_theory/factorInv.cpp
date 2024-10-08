#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define endl '\n'
const i64 m = 1e9+7;

/* 
    阶乘求逆元
    我们已经知道3中求逆元的方法，接下来我们讨论一下阶乘逆元，我们定义 fac[i] 为 i!
    ifac[i] 为 (i!)' 也就是 fac[i] 的逆元

    我们看到：

    ifac[i]*fac[i] = 1 mod m

    ifac[i]*fac[i-1]*i = 1 mod m

    (ifac[i]*i) * fac[i-1] = 1 mod m

    显然 ifac[i-1] = ifac[i] * i

    那么我们只需要先求出 fac[n]，然后使用扩展欧里几得，或者快速幂，求出 ifac[n]，
    接着线性递推出所有的 ifac[i] 就好了
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