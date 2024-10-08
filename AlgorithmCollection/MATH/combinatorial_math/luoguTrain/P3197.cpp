/* 
    存在 n 个不同的球, m 个相同的盒子
    随机放入，不能空盒。
    
    求有多少种情况 相邻 2 个盒中球的颜色相同
 
    正面难以突破，考虑容斥。总情况减去每相邻都不重复即可

    n^m - n * (n-1) * (n-1) * ... = n^m - n * (n-1)^{m-1}
 */
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int md = 100003;

struct mInt
{
    long long var;

    static long long mod; //指定模数

    mInt(long long x) {
        var = x;
    }

    mInt(const mInt& x) {
        var = x.var;
    }

    mInt& operator+(const mInt& x) {
        var = (var % mod + x.var % mod + mod) % mod;
        return *this;
    }

    mInt& operator*(const mInt& x) {
        var = ((var % mod) * (x.var % mod) + mod) % mod;
        return *this;
    }

    mInt& operator-(const mInt& x) {
        var = (var % mod - x.var % mod + mod) % mod;
        return *this;
    }
};
long long mInt::mod = md;



mInt fastPow(mInt x, int a) {
    mInt ans{1};
    while (a) {
        if (a & 1) ans = ans * x;
        x = x * x;
        a >>= 1;
    }
    return ans;
}

signed main()
{
    int n,m;
    cin >> n >> m;

    mInt a = fastPow(n,m);
    mInt b = fastPow(n-1,m-1) * n;

    cout << (a-b).var << endl;

    system("pause");
    return 0;
}
