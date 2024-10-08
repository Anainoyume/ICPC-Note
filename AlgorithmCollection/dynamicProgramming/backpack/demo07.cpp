#include <bits/stdc++.h>
using namespace std;

const int maxN = 25;
int n;
int arr[maxN];
int dp[1205];
int cnt[4];

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 4; i++)
        cin >> cnt[i];
    
    int ans{};
    for (int i = 0; i < 4; i++)
    {
        int cur = cnt[i];
        int sum{};
        fill(begin(arr),end(arr),0);
        fill(begin(dp),end(dp),0);
        //ÕÛ°ëÇó½â
        for (int j = 1; j <= cur; j++) {
            cin >> arr[j];
            sum += arr[j];
        }
        
        for (int m = 1; m <= cur; m++)
        {
            for (int v = sum/2; v >= 0; v--)
            {
                if (v >= arr[m]) dp[v] = max(dp[v],dp[v-arr[m]]+arr[m]);
            }
        }
        
        ans += max(dp[sum/2],sum-dp[sum/2]);
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}
