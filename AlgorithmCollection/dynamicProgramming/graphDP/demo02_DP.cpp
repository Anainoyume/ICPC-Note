#include <bits/stdc++.h>
using namespace std;

const int maxN = 100+5;
int n,m;
int g[maxN][maxN];
int dp[maxN][maxN];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int ans;
/* 
    有记忆化搜索一定有DP，记忆化搜索就是DP的一种形式
    不过我们是自顶向下推的DP。而DP是自底向上递推。

    我们现在就来试试DP求解。

    经过约30分钟的尝试，这题是不能用双重for循环来dp的
    dfs有顶向下拓展，其实就是找那个不能再继续走的点。

    如果像自底向上进行dp，可以采取bfs拓展。每个点拓展出去。
    但这样就反而还不如直接写一个 dfs 了。

    所以我们还是采取记忆化搜索

 */
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            dp[i][j] = 1;
        }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         for (int k = 0; k < 4; k++)
    //         {
    //             int tx = i+dx[k];
    //             int ty = j+dy[k];
    //             if (tx <= 0 || tx > n || ty <= 0 || ty > m) continue;
    //             if (g[tx][ty] > g[i][j])
    //                 dp[tx][ty] = max(dp[i][j]+1,dp[tx][ty]);
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    cout << ans << endl;


    system("pause");
    return 0;
}