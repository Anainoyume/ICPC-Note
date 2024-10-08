#include <bits/stdc++.h>
using namespace std;

const int maxN = 100+5;
int n,m;
int g[maxN][maxN];
int dp[maxN][maxN];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int ans;
int dfs(int x, int y) {
    if (dp[x][y]) return dp[x][y];

    for (int i = 0; i < 4; i++)
    {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if (tx <= 0 || tx > n || ty <= 0 || ty > m) continue;

        if (g[tx][ty] < g[x][y]) {
            dp[x][y] = max(dfs(tx,ty)+1,dp[x][y]);
        }
    }
    
    return dp[x][y] ? dp[x][y] : dp[x][y] = 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
        
    //先试试传统记忆化搜索
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(dfs(i,j),ans);
    
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