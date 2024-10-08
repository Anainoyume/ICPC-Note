/* 
    链接：https://codeforces.com/gym/489511/problem/I
 */
#include <bits/stdc++.h>
using namespace std;

/* 
    介绍位运算符的作用：

    我们都知道  a & 1 是判断奇偶性的作用
    那么 a & 1 ^ 1 的作用是什么呢？
    答案是反转奇偶性

 */

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;

    int sum = 0;             // 用于记录当前位置之前的数字之和
    long long a[2] {1, 0}; // 用于记录奇数和偶数1的子区间个数
    long long ans = 0;       // 最终的答案，即包含奇数个1的子区间的数量

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        sum += x;             // 将当前数字（0或1）加到之前数字之和中
        ans += a[sum & 1 ^ 1]; // 根据当前的和，更新答案，增加包含奇数个1的子区间的数量
        a[sum & 1]++;         // 更新奇数和偶数1的子区间个数
    }

    cout << ans << "\n";

    system("pause");
    return 0;
}
