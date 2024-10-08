#include <bits/stdc++.h>
using namespace std;
#define ll long long

const ll maxN = 1e5+5;
ll sum[45][45], n;
ll dp[45][maxN];

int main(int argc, char const *argv[])
{
    string num{};
    cin >> num >> n;

    fill(dp[0],dp[0]+45*maxN,INT_MAX);

    ll len = num.size();
    for (ll i = 1; i <= len; i++)
    {
        for (ll j = i; j <= len; j++)
        {
            sum[i][j] = sum[i][j-1] * 10 + (num[j-1]-'0');
            if (i == 1 && sum[i][j] <= n && sum[i][j] >= 0) dp[j][sum[i][j]] = 0;
        }
    }
    
    //dp[0][0] = -1;
    for (ll i = 1; i <= len; i++)
    {
        for (ll j = 0; j <= n; j++)
        {
            for (ll k = i; k >= 1; k--)
            {
                if (sum[k][i] > n) break;
                if (j >= sum[k][i] && k >= 1) 
                    dp[i][j] = min(dp[i][j],dp[k-1][j-sum[k][i]]+1);
            }
        }
    }
    
    cout << ((dp[len][n] <= len-1) ? dp[len][n] : -1) << endl;
    
    system("pause");
    return 0;
}
