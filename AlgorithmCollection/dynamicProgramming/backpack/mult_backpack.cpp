//标准的完全背包
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c表示体积, w是价值
int dp[10001][10001];

//朴素完全背包算法
int main()
{
    cin >> C >> n;  //C为背包容量，n为物品数量，每个物品有无限个

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    //将k个物品单独拉出来，看最多能拿加个，本质还是01背包
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= C; j++) {
            dp[i][j] = dp[i-1][j];

            for (int k = 0; k <= C/c[i]; k++) {
                if (k*w[i] <= j) {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-k*c[i]]+k*w[i]);
                }
            }
        }
    }
    
    cout << dp[n][C] << endl;

    system("pause");
    return 0;
}