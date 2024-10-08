#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int lose[1005];
int win[1005];
int use[1005];

int main(int argc, char const *argv[])
{
    int n{}, k{};   
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)    //为什么 j 一定要从 0 开始？
        {                               // 因为 j 代表的 是 容量，容量有用完的情况！！！
            if (j < use[i]) 
                dp[i][j] = dp[i-1][j]+lose[i];
            else
                dp[i][j] = max(dp[i-1][j]+lose[i],dp[i-1][j-use[i]]+win[i]);
        }
    }

    cout << dp[n][k]*5 << endl;
    
    system("pause");
    return 0;
}
