/* 
    最大子序列和

    一个序列存在 正数，负数 找出这个序列的最大的子序列和，要求子序列连续
 */
#include <bits/stdc++.h>
using namespace std;

//区别于最长子序列
int n, nums[10010], dp[10010];
/* 
    dp数组的含义：以i结尾的最大子序列和
    因此当我们计算dp[i]的时候
    我们已经知道
    dp[i-1]的结果

    因此分两种情况，要么延续dp[i-1]的结果，加长序列，要么总序列和还不如nums[i]当前一个数字大，
    我们取两者的最大值

    dp[i] = max(dp[i-1]+nums[i],nums[i]);

    其实有了这个递推表达式，写代码就已经无压力了
 */

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    dp[0] = nums[0];
    int ans = dp[0];
    for (int i = 0; i < n; i++) //时间复杂度为 O(n)
    {
        dp[i] = max(dp[i-1]+nums[i],nums[i]);
        ans = max(ans,dp[i]);
    }
    
    cout << ans << endl;
}

int main()
{
    int t = 0;
    cin >> t;

    while (t--) {
        solve();
    }

    system("pause");
    return 0;
}