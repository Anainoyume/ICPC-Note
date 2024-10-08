/* 
    令dp[i][j]表示把word1的前i个字符转化成word2的前j个字符的最小操作次数。
    首先考虑两种简单的特殊情况，当对空字符进行转化和转化成空字符的时候：

    dp[0][j] = j;
    dp[i][0] = i;

    然后对于通常情况，假设我们已经知道dp[i-1][j-1]，同样分成两种进行考虑：
    当word1[i-1] == word2[j-1]时， 在dp[i-1][j-1]的基础上， 不再需要进行操作，则dp[i][j] = dp[i-1][j-1]
    当word1[i-1] != word2[j-1]时，可能进行的操作有插入，删除，替换三种，分三种情况讨论：

    插入：假如我们已经知道dp[i][j-1]，即字符串word1[0...i-1]能转化成word2[0...j-2]，
    那么只需要在word1[0...i-1]后面插入word2[j-1]即可，所以dp[i][j] = dp[i][j-1] + 1;

    删除：类似地， dp[i][j] = dp[i-1][j] + 1;

    替换：类似地，dp[i][j] = dp[i-1][j-1] + 1;
    到此为止，已经找到了解决该问题的完整的状态转移方程，就可以用dp解决了。

 */
#include <bits/stdc++.h>
using namespace std;
int word_change(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        dp[i][0] = i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = i;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1]) // 状态转移方程：立足一个普通的点，进行分析所有状态可能；
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }
    return dp[n][m];
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << word_change(s1, s2) << endl;
    ;
}