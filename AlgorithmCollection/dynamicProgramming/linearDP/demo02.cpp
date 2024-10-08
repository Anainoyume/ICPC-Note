/* 
    最大字段和
 */
#include <bits/stdc++.h>
using namespace std;

/* 
    我们先考虑如何设计状态转移方程
    1. 首先产生的直觉应该是 设计 dp[i] 表示[1,i]的最大字段和
    但是因为字段要求必须是连续的
    如果出现

    -2 -4 3 4 5 -2 -1 4 9
         [3 4 5]      ^

    这种情况，也就是与下一个b[i]断开了，这样我们的递推方程是设计不了的。

    2. 这样，我们定义dp[i]为 “以i结尾的最大字段和”
    b[i]: -2 -4 3 4 5 -2 -1 4 9
     i:    1  2 3 4 5  6  7 8 9

    dp[1] = [-2]                    = -2
    dp[2] = [-4]                    = -4
    dp[3] = [3]                     = 3
    dp[4] = [3 4]                   = 7
    dp[5] = [3 4 5]                 = 12
    dp[6] = [3 4 5 -2]              = 10
    dp[7] = [3 4 5 -2 -1]           = 9
    dp[8] = [3 4 5 -2 -1 4]         = 13
    dp[9] = [3 4 5 -2 -1 4 9]       = 22

    我们可以从中窥见一些规律吗？
    如果 dp[i-1] + b[i] 的值，甚至比b[i]还小。
    那么我们就另起1组

    所以 dp[i] = max( b[i] , dp[i-1] + b[i] );
    初始化 dp[1] = b[1];
 */

int main(int argc, char const *argv[])
{
    int n{};
    cin >> n;
    int b[n+1]{};
    for (size_t i = 1; i <= n; i++)
        cin >> b[i];
    
    int dp[n+1]{};

    dp[1] = b[1];   
    int ans = dp[1];
    for (size_t i = 2; i <= n; i++)
    {
        dp[i] = max(b[i], dp[i-1]+b[i]);
        ans = max(ans,dp[i]);
    }
    
    cout << ans << endl;
    
    system("pause");
    return 0;
}


