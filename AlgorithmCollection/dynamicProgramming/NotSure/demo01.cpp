#include <bits/stdc++.h>
using namespace std;

const int maxN = 105;
int n, m;
int w[maxN];

int dp[maxN][1005];

int dfs(int cur, int sum) {
    if (dp[cur][sum]) return dp[cur][sum];

    if (sum > m) return 0;

    if (cur > n) {
        if (sum == m) return 1;
        else return 0;
    }
    //当前这道菜，选或者不选
    dp[cur][sum] = dfs(cur+1,sum) + dfs(cur+1,sum+w[cur]);
    return dp[cur][sum];
}

int main(int argc, char const *argv[])
{
    
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    
    int ans = dfs(1,0);

    cout << ans << endl;

    system("pause");
    return 0;
}
