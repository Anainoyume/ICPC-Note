#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
/*
    这里介绍至少三种方法来求乘法逆元
    由于 ab = 1 mod m，
    我们根据数论学过的知识，知道这说明 ab mod m = 1 mod m = t
    所以 ab = km + t,  1 = sm + t
    所以 ab-1  = (k-s)m
    我们移项，得到 ab + (s-k)m = 1
    假设我们要求 a 的乘法逆元 b，我们假设 b 为 x， 假设 s-k 为 y
    于是我们就有了：
    ax + my = 1
    a,m 已知，我们写成 a,b的形式

    那么就是 ax + by = 1

    那么这个问题很显然可以使用 扩展欧里几得算法解决
 */
// 1. 扩展欧里几得算法
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
        return x < 0 ? x + m : x;   //注意如果求出来x小于0，我们要补回1个m
    else
        return -1;
}


// 2. When p is Prime and gcd(a,p) is equal to 1，利用费马小定理
/* 
    我们知道费马小定理：
    a^{p-1} = 1 mod p

    那么 a * a^{p-2} = 1 mod p

    显然这种情况下， a^{p-2} 就是 a 的 乘法逆元
    我们使用带模快速幂来求解
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


//3. 线性求逆元
/* 
    有时候数据规模量比较大，我们需要求 1~n 内线性个元素的逆元
    我们有更快的方法：(打一瓢表示逆元)

    考虑 p = ki + r
    那么 ki + r = 0 mod p
    ki (i'r') + r (i'r') = 0 mod p
    kr' + i' = 0 mod p
    i' = -kr' mod p
    i' = -(p/i)r' mod p

    又因为 k = p/i ; r = p%i

    i' = -(p/i)*(p%i)' mod p

    那么假如我们知道 (p%i)'，就可以得出 i'
    这是一个递推式子
 */
vector<i64> linearInv(i64 n, i64 p) {
    vector<i64> inv(n,0);
    inv[1] = 1;

    for (i64 i = 2; i <= n; i++) {
        // -(p/i) 在 % p 的情况下再 +p ,防止出现负数逆元
        inv[i] = (p - p/i) * inv[p % i] % p;
    }
    return inv;
}

int main()
{

    i64 n{}, p{};
    cin >> n >> p;

    //另外做这题的时候卡了endl，换成\n可过
    auto inv = linearInv(n,p);

    cout << 1 * inv[3] % p << endl;

    system("pause");
    return 0;
}