/* 
    快速幂
    幂运算 a^n 即 n个a 相乘
    但我们使用暴力算法的结果，时间复杂度为 O(n) ,因为我们需要将n个a相乘
    我们不禁思考是否存在 更快速的方法
 */
#include <bits/stdc++.h>
using namespace std;

long long quickCount(int a, int n) {
    /*
        我们思考，例如要求 a^8
        我们是否可以 a*a = a^2
        再进行自乘 a^2 * a^2 = a^4
        a^4 * a^4 = a^8
        这样就把时间复杂度降到了 O(logn)
    */
    if (n == 0) return 1;
    if (n == 1) return a;
    long long temp = quickCount(a,n/2);
    if (n & 1 == 1) 
        return temp*temp*a;
    else 
        return temp*temp;
}

int main(int argc, char const *argv[])
{
    cout << quickCount(2,31) << endl;
    
    system("pause");
    return 0;
}
