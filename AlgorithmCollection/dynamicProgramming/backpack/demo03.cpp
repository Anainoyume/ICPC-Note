#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[105][1005], w[105];
//dp[i][j]表示前i个物品恰好凑出j元的情况数

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            //不选
            dp[i][j] += dp[i-1][j];
            //选
            if (j >= w[i]) dp[i][j] += dp[i-1][j-w[i]];
        } 
    }
    
    cout << dp[n][m] << endl;

    system("pause");
    return 0;
}
