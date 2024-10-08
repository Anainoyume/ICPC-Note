#include <bits/stdc++.h>
using namespace std;

inline int64_t mul(int64_t x, int64_t y, int64_t p) {
    int64_t z = (long double)x / p * y;
    int64_t res = (uint64_t)x * y - (uint64_t)z * p;
    return (res + p) % p;
}

inline int64_t gcd(int64_t a, int64_t b) {
    return b ? gcd(b, a % b) : a;
}

inline int64_t fastPow(int64_t a, int64_t x, int64_t m) {
    int64_t ans = 1ll;
    while (x) {
        if (x&1) ans = mul(ans, a, m);
        a = mul(a, a, m);
        x >>= 1;
    }
    return ans;
}

bool millerRabin(int64_t n) {
    if (n < 3 || n % 2 == 0) return n == 2;
    if (n % 3 == 0) return n == 3;

    int64_t u = n - 1;
    int t = 0;
    while (u % 2 == 0) u /= 2ll, t += 1;
    int test_time = 10;
    for (int i = 0; i < test_time; ++i) {
        int64_t a = rand() % (n - 3ll) + 2ll, v = fastPow(a, u, n);
        if (v == 1) continue;
        int s{};
        for (s = 0; s < t; ++s) {
            if (v == n - 1) break; 
            v = mul(v, v, n);
        }
        if (s == t) return false;
    }
    return true;
}

inline int64_t PollardRho(int64_t x) {
    int64_t s{}, t{}, c{1ll * rand() % (x-1) + 1};
    int step{}, goal{1};
    int64_t val{1};
    for (goal = 1; ; goal <<= 1, s = t, val = 1) {
        for (step = 1; step <= goal; ++step) {
            t = ((__int128)t * t + c) % x;
            val = (__int128)val * abs(t-s) % x;
            if ((step % 127) == 0) {
                int64_t d = gcd(val,x);
                if (d > 1) return d;
            }
        }
        int64_t d = gcd(val, x);
        if (d > 1) return d;
    }
}

void factor(int64_t x, vector<int64_t>& facs) {
    if (x < 2)
        return;
    if (millerRabin(x)) {
        facs.push_back(x);
        return;
    }
    int64_t p = x;
    while (p >= x)
        p = PollardRho(x); // 使用该算法
    factor(x/p, facs), factor(p, facs); // 继续向下分解x和p
}

signed main()
{
    int64_t x = 2*2*3*4*5*5*7*9*13;
    vector<int64_t> facs;
    factor(x,facs);

    int64_t res = 1;
    for (auto&& fac : facs) {
        res *= fac;
    }

    //可以使用stl函数归一化因数
    sort(facs.begin(),facs.end());
    facs.erase(unique(facs.begin(),facs.end()),facs.end());

    cout << res << endl;

    system("pause");
    return 0;
}