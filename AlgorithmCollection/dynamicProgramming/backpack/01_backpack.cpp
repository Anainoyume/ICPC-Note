//标准的01背包
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c表示体积, w是价值
int dp[10001][10001];

int main()
{
    cin >> C >> n;  //C为背包容量，n为物品数量

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            if (c[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
                //如果当前容量可以放得下
                /* 
                    1. 不放
                    不放就是 dp[i-1][j]
                    2. 放
                    dp[i-1][j-c[i]]+w[i]
                    表示，先获取前 i-1 个物品，在容量为 j-c[i]  背包中所放的最大价值，
                    再加上当前这个物品的价值
                    
                    我们将二者取最大值
                 */
        }
    }
    
    cout << dp[n][C] << endl;

    system("pause");
    return 0;
}