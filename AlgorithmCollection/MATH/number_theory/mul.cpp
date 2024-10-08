#include <bits/stdc++.h>
using namespace std;
/* 
    两种处理大数的快速乘
 */
inline int64_t mul(int64_t x, int64_t y, int64_t p) {
    int64_t z = (long double)x / p * y;
    int64_t res = (uint64_t)x * y - (uint64_t)z * p;
    return (res + p) % p;
}

inline int64_t mul(int64_t a, int64_t b, int64_t MOD) {
    __int128 x = a, y = b, m = MOD;
    return (int64_t)(x * y % m);
}

signed main()
{
    

    system("pause");
    return 0;
}