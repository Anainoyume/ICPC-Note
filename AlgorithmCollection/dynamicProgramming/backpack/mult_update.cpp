/* 
    多重背包滚动数组优化
 */
//多重背包 时间优化+空间优化
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c表示体积, w是价值
int dp[10001];

int main()
{
    cin >> C >> n;  //C为背包容量，n为物品数量，每个物品有无限个

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = c[i]; j <= C; j++)
        {
            dp[j] = max(dp[j],dp[j-c[i]]+w[i]);  //式子可以推导
        }
    }
    
    cout << dp[C] << endl;

    system("pause");
    return 0;
}