//标准的完全背包
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c表示体积, w是价值
int dp[10001];

//滚动数组 优化 完全背包
int main()
{
    cin >> C >> n;  //C为背包容量，n为物品数量，每个物品有无限个

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    //滚动数组，压维优化
    for (int i = 1; i <= n; i++)
    {
        for (int j = C; j >= 1; j--)
        {
            for (int k = 0; k <= C/c[i]; k++)
            {
                dp[j] = max(dp[j],dp[j-k*c[i]]+k*w[i]);
            }
        }
    }
    
    cout << dp[C] << endl;

    system("pause");
    return 0;
}