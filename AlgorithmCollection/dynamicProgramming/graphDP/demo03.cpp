/* 
    食物链计数
 */
#include <bits/stdc++.h>
using namespace std;

const int m = 80112002;
const int maxN = 5005;
int n, k;
bool g[maxN][maxN];
int inDeg[maxN];
int outDeg[maxN];
int dp[maxN];

int ans;
int dfs(int x) {
    if (dp[x]) return dp[x] % m;
    if (!outDeg[x]) return dp[x] = 1;

    int subPath{};
    for (int i = 1; i <= n; i++)
    {
        if (g[x][i]) {
            dp[x] += (dfs(i) % m);
        }
    }
    return dp[x] % m;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int from{}, to{};
        cin >> from >> to;
        g[from][to] = 1;
        inDeg[to]++;
        outDeg[from]++;
    }
    
    for (int i = 1; i <= n; i++)
    {
        if (!inDeg[i]) {
            ans += (dfs(i) % m);
        }
    }
    
    cout << ans % m << endl;

    system("pause");
    return 0;
}