#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/* 
    拓展欧里几得算法
 */
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

int main()
{
    

    system("pause");
    return 0;
}