#include <bits/stdc++.h>
using namespace std;

int val = (-1)*INT_MAX;
const int maxN = 2e5+5;
int n, l, r;
int arr[maxN];
int dp[maxN];

int dfs(int cur) {
    if (dp[cur] != val) return dp[cur];
    if (cur+l > n) {
        return arr[cur];
    } 
    for (int i = l; i <= r; i++)
    {
        dp[cur] = max(dp[cur],dfs(cur+i)+arr[cur]);
    }
    return dp[cur];
}

int main(int argc, char const *argv[])
{
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
        dp[i] = val;
    }
    
    int ans = dfs(0);

    cout << ans << endl;

    system("pause");
    return 0;
}
