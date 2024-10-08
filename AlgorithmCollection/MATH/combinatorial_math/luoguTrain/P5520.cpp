/* 
    n 个位置
    m 颗树

    每 2 颗树之间要存在至少 1 个空位。问所有可能的种植方案

    插空法：

    先拿出 m 颗树，我们还剩 n-m 个位置

    我们将 树连带着它自己的位置 插入到剩下的 n-m 位置之间的间隔里去，这样就可以保持至少相隔一个了。
    由于树存在编号，使用排列。但要注意 n-m 的间隔存在 n-m+1 个，这是因为最变上会多出 1 个空位。即没有树种在最两边

    答案：A[n-m+1][m] = c[n-m+1][m] * fac[m]

    但是这题范围过大，无法预处理组合数，那么我们只能使用 滚动数组 来一次性处理我们的值。
    使用排列递推式：

    A[m][n] = A[m-1][n] + n*A[m-1][n-1];

    但更简单的是，由于：
    A[m][n] = n! / (m-n)! = (m-n+1)*(m-n+2)* ... *m
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int index, pos, tree, mod;
    cin >> index >> pos >> tree >> mod;

    int ans{1};
    for (int i = pos-2*tree+2; i <= pos-tree+1; ++i) {
        ans = (ans % mod * (i % mod)) % mod;
    }

    cout << ans << endl;

    system("pause");
    return 0;
}