/* 
    递推求组合数
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5+5;
const int md = 1e9+7;

// 递推求阶乘
int c[maxN][maxN];
void getCombine() {
    for (int i = 0; i < maxN; i++) {
        for (int j = 0; j <= i; j++) {
            if(j == 0) c[i][j] = 1;
            else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % md;
        }
    }
}

int64_t fastPow(int64_t a, int64_t n, int64_t m = md) {
    int64_t ans{1};
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

// 逆元求 取模组合数，注意逆元是否为质数
int C(int m, int n) {
    if (n == m || n == 0) return 1;
    return (fac[m] % md * (fastPow((fac[m-n] % md * (fac[n] % md)) % md,md-2) % md)) % md;
}

int main()
{

    
    system("pause");
    return 0;
}