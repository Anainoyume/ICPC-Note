/* 
    错排问题
    递推式：
    D[n] = (n-1)*(D[n-1] + D[n-2])
 */

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int md = 1e9+7;
const int maxN = 1e6+5;

int D[maxN];
void getDerangement() {
    D[0] = 1;   //等于 0 的时候不用重排，不要影响到特殊情况的答案
    D[1] = 0, D[2] = 1;
    for (int i = 3; i < maxN; ++i) {
        D[i] = (i-1) % md * (((D[i-1] % md + D[i-2] % md) % md) % md) % md;
    }
}

using i64 = long long;
i64 fastPow(i64 a, i64 n, i64 m = md) {
    i64 ans{1};
    while (n) {
        if (n&1) ans = (ans*a) % m;
        a = (a*a) % m;
        n >>= 1;
    }
    return ans;
}

// 计算阶乘
int fac[maxN];
void getFactorial() {
    for (int i = 0; i < maxN; ++i) {
        if (i == 0) fac[i] = 1;
        else fac[i] = (i % md * fac[i-1] % md) % md;
    }
}

// 逆元求 取模组合数
int C(int m, int n) {
    if (n == m || n == 0) return 1;
    return (fac[m] % md * (fastPow((fac[m-n] % md * (fac[n] % md)) % md,md-2) % md)) % md;
}

signed main()
{
    getFactorial();
    getDerangement();

    int t{};
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        cout << C(n,m) % md * (D[n-m] % md) % md << endl;

    }
    

    system("pause");
    return 0;
}