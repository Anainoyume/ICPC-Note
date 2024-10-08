/* 
    n <= 10^5
    求解这其中满足 a^2 + b^2 = c^2 的数
    a <= b <= c

    普通扫描肯定无法通过

    我们考虑式子变形
    a^2 = (c-b)(b+c);

    我们令 c-b = x;  c+b = y;

    c = (x+y)/2;
    b = (y-x)/2;    我们观察到，如果b,c均为整数，那么x,y的奇偶性一定相同

    而且看起来，x和y显然是a^2的因数

    那么就好说了！
    我们直接求出a^2所有的因数

    a^2 所有质因子怎么求？
    显然 a可以分解
    a = p1p2p3p4p5.... (这里没写指数)
    a^2 显然就只是把a所有质因子的指数乘以二

    如何精确一个数字的每一个因子呢？
    1.先进行质因子分解
    2.再使用搜索枚举每一个因子
    例如: 100 = 2^2*5^2
    2 5
    指数从0开始搜索
    2*1 = 2
    1*5 = 5
    2*2*1 = 4
    1*5*5 = 25
    2*5 = 10
    2*2*5 = 20
    2*5*5 = 50

    我们在所有的因子里枚举x

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
