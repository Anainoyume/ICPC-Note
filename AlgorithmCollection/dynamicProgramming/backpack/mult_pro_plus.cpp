//多重背包 时间优化+空间优化
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c表示体积, w是价值
int dp[10001][10001];

int main()
{
    cin >> C >> n;  //C为背包容量，n为物品数量，每个物品有无限个

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            if (j - c[i] >= 0)
                dp[i][j] = max(dp[i-1][j],dp[i][j-c[i]]+w[i]);  //式子可以推导
            else 
                dp[i][j] = dp[i-1][j];
            /* 
                或者我们尝试理解这个式子
                dp[i][j] 表示尽量多选择物品所得到得最大值

                dp[i][j] = dp[i][j-c[i]]+w[i] 的含义便是第i个物品一直选择

                而 dp[i][j] = dp[i-1][j] 的含义则是，继承上一个充分选择的物品


             */
        }
    }
    
    cout << dp[n][C] << endl;

    system("pause");
    return 0;
}