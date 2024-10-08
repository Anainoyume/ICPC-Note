#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    string str{};
    cin >> str;
    int n = str.size();

    int dp[n+2][n+2]{}; //dp[i][j] 表示变成回文串的最小的次数！

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i < n-len+1; i++)
        {
            if (str[i] == str[i+len-1]) {
                dp[i][i+len-1] = dp[i+1][i+len-2];
            }
            else {
                dp[i][i+len-1] = min(dp[i][i+len-2],dp[i+1][i+len-1]) + 1;
            }
        }
    }
    
    cout << dp[0][n-1] << endl;
    

    system("pause");
    return 0;
}