#include <bits/stdc++.h>
using namespace std;
/* 
    计算 1 ~ n 的数字的数位和 的 总和
 */
const int maxN = 1e5+5;
int n, dp[maxN], ans[maxN];

int main()
{
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        dp[i] = i;
        if (i > 0) ans[i] = ans[i-1] + dp[i];
    }

    for (int i = 10; i <= n; i++) {
        dp[i] = dp[i%10] + dp[i/10];
        ans[i] = ans[i-1] + dp[i];
    }
    
    cout << ans[n] << endl;

    system("pause");
    return 0;
}