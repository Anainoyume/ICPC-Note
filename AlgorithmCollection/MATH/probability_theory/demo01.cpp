/* 
    概率dp
 */
#include <bits/stdc++.h>
using namespace std;

int n,k;
double dp[405][405];

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) 
    {
        //这里的 i < j 时结果为0，不用考虑
        //因为不可能只翻2次却翻出3枚正面
        for (int j = 0; j < n; j++)
        {
            dp[i+1][j+1] += 0.5*dp[i][j];
            dp[i+1][j] += 0.5*dp[i][j];
        }
        //循环结束以后此时 j == n
        dp[i+1][n] += 0.5*dp[i][n];
        dp[i+1][n-1] += 0.5*dp[i][n];
        //不会出现 n+1 的情况，因为最多只有n枚
    }
    
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += i*dp[k][i];
    }
    
    printf("%.6lf\n",ans);  //保留6位小数
    
    system("pause");
    return 0;
}


