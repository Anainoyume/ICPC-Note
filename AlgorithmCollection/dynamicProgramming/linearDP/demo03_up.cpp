#include <bits/stdc++.h>
using namespace std;

int val = INT_MIN;
const int maxN = 2e5+5;
int n, l, r;
int arr[maxN];
int dp[maxN];

int main(int argc, char const *argv[])
{
    cin >> n >> l >> r;
    for (int i = 0; i <= n; i++) {
        cin >> arr[i];
        dp[i] = val;
    }
    dp[0] = 0;
    int ans = val;
    for(int i = l; i <= n; i++)
    {
        for (int k = 0; k <= r-l; k++) {
            if (i >= r-k && dp[i-r+k] != val) {
                dp[i] = max(dp[i], dp[i-r+k] + arr[i]);
            }
        }

        if(i + r > n) 
            ans = max(dp[i], ans);
    }

    for (int i = 0; i <= n; i++)
    {
        cout << dp[i] << " ";
    }
    cout << endl;
    
    cout << ans << endl;
    
    system("pause");
    return 0;
}
