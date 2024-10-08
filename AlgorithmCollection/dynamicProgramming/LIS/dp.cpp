#include <bits/stdc++.h>
using namespace std;

const int maxN = 5005;
int n;
int a[maxN];
int dp[maxN];

int main(int argc, char const *argv[])
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i] = 1;
    }
    
    int ans{};
    //LIS问题的dp解法，定义 dp[i]为以i结尾的最长上升子序列的长度
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[i] > a[j]) dp[i] = max(dp[i],dp[j]+1);
        }
        ans = max(ans,dp[i]);
    }
    
    cout << ans << endl;
    
    system("pause");
    return 0;
}
