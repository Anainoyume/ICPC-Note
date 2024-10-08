#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

/* 
    题目链接：https://www.luogu.com.cn/problem/P1435
    回文字串
 */

//这题有两个做法，一个是编辑距离的做法
void solve1()
{
    string str{};
    cin >> str;
    int len = str.size();

    int dp[len+5][len+5]{};
    // dp[i][j] 表示 str从i到j转化成回文串需要多少字符

    for (int i = len; i >= 1; i--)
    {
        for (int j = i; j <= len; j++)  //注意画图来看转移方向
        {
            if (i == j) dp[i][j] = 0;
            if (str[i-1] == str[j-1]) {
                dp[i][j] = dp[i+1][j-1];
            }
            else {
                dp[i][j] = min(dp[i+1][j],dp[i][j-1])+1;
            }
        }
    }
    cout << dp[1][len] << endl;
}


//最长公共子序列做法
/* 
    既然回文串的特点是正着读反着读一样，那么我们可以先反向字符串。
    再将两个字符串进行最长公共子序列的匹配。
    没匹配上的字符显然我们各自补一个字母即可。
 */
void solve2()
{
    string s1{};
    cin >> s1;
    string s2{s1};
    reverse(s2.begin(),s2.end());

    int len = s1.size();
    int dp[len+1][len+1]{};

    for (int i = 1; i <= len; i++) {
        for (int j = 1; j <= len; j++) {
            if (s1[i-1] == s2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    cout << len - dp[len][len] << endl;

}

int main()
{
    solve2();
    
    system("pause");
    return 0;
}