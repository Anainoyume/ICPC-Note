/* 
    这是demo02.cpp一个比较好理解的做法，也是最初的状态转移方程
 */
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> b(n,0);
    for (auto &&ele : b)
        cin >> ele;
    
    int dp[n+1][n+1];
    fill(dp[0],dp[0]+(n+1)*(n+1),0);

    if (b[0]) dp[0][1] = 1;
    else dp[0][0] = 1;

    /* 
        核心代码在这个地方，dp数组的含义表示：以i结尾的奇(偶)数个1子数组的数量

        1 0 0 1 0 0

        dp[0][1] = 1; 因为第一个元素为1，所以以 i=0 结尾的子数组，有 [1]，因此dp[0][1] = 1;

        到 i=1, b[1] = 0;
        所以当前位置上的
        dp[1][1] = dp[0][1]; 因为这个时候1个奇偶性没有变化，只是末尾多了一个0而已，也就是 [1 0] 这个子数组
        dp[1][0] = dp[0][0] + 1; 这个时候同样从奇偶性相同的转移过来，但是偶数个1(注意偶数包括0)的子数组，有 [0]

        到 i=2, b[2] = 0;
        dp[2][1] = 1; 为 [1 0 0] 只是末尾多个0而已
        dp[2][0] = 2; 因为这个时候不仅末尾多了1个0，继承之前的 [0 0] 为一个子数组，本身自己这个[0] 也是一个子数组

        到 i=3, b[3] = 1;
        dp[3][1] = dp[2][0] + 1; 这个时候奇偶性变了，要从偶数子数组那边转移过来
        我们知道dp[2][0] 是 [0 0] 和 [0] ，这是我们只是在末尾加个1，有 [0 0 1] [0 1]，自己的[1]也为1个子数组
        所以 dp[3][1] = 3;
        dp[3][0] = dp[2][1]; 我们的dp[2][1]为 [1 0 0]，这个时候我们只是在末尾加个1而已，为[1 0 0 1]
        所以 dp[3][0] = 1;

        1 0 0 1 0 0

        到 i=4, b[4] = 0;
        dp[4][1] = dp[3][1];
        dp[3][1]有 [0 0 1] [0 1] [1],我们只是在末尾加个0
        [0 0 1 0] [0 1 0] [1 0]。所以dp[4][1] = 3;
        dp[4][0] = dp[3][0] + 1;
        dp[3][0]有 [1 0 0 1]，所以dp[4][0]为[1 0 0 1 0]和[0]
     */
    for (int i = 1; i < n; i++)
    {
        if (b[i]) {
            dp[i][1] = dp[i-1][0] + 1;
            dp[i][0] = dp[i-1][1];
        }
        else {
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1];
        }
    }
    
    int ans{};
    for (int i = 0; i < n; i++)
    {
        ans += dp[i][1];
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}

