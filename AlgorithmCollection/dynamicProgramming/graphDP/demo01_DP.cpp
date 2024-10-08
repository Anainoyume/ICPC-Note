/*
    这是demo01.cpp的dp解法
 */
#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n;
int nodes[maxN];
bool g[maxN][maxN];
int dp[maxN];
int last[maxN];
int ans, k;

void print(int i) {
    if (i == 0) return;
    print(last[i]);
    cout << i << " ";
    if (i == k) cout << endl;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> nodes[i];
        dp[i] = nodes[i];
    }
    
    for (int i = 1; i <= n-1; i++)
        for (int j = i+1; j <= n; j++)
            cin >> g[i][j];
        
    // 解法参考博客：https://blog.csdn.net/sai_2021/article/details/119788912
    /* 
        讲的非常的好。

        而接下来，我来说说我现在的观点（By the way，做这题时状态特别好）
        首先我们要明白一件事：
        这题，看起来是图，实际上是树。

        树形dp 明白了吗？

        树形有天然的子结构和无后效性，是自然而然的dp
        
        所以这题要理解这题是树而不是图。图存在往前走的可能性。但这道题是树结构。
        所以我们一直靠近树的叶子节点，逐层向下dp就可以了。
     */

    for (int i = 1; i <= n; i++)
    {
        for (int j = i+1; j <= n; j++)
        {
            if (g[i][j] && dp[i]+nodes[j] > dp[j]) {
                dp[j] = dp[i]+nodes[j];
                last[j] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dp[i] > ans) {
            ans = dp[i];
            k = i;
        }
    }
    
    print(k);
    cout << ans << endl;

    system("pause");
    return 0;
}