#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define int long long
#define endl '\n'
#define double long double

const int md = 1e9+7;
const int maxN = 1005;
bool arr[105][105];
int dp[105][105];

signed main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (arr[i][j] == 0) 
                dp[i][j] = 0;
            else 
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;

            ans = max(ans,dp[i][j]);
        }
    }
    
    cout << ans << endl;
    
    system("pause");
    return 0;
}
