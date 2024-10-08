#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int maxN = 1e6+5;
const int md = 1e9+7;
int dp[maxN];

int fastPow(int a, int x) {
    int ans = 1;
    while (x) {
        if (x & 1) ans = ((ans % md) * (a % md)) % md;
        a = ((a % md) * (a % md)) % md;
        x >>= 1;
    }
    return ans;
}

signed main()
{
    int n = 0;
    cin >> n;

    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = ((i % md) * (dp[i-1] % md)) % md;
    }
    
    cout << (md + ((dp[n] % md) - (fastPow(2,n-1) % md))) % md << endl;
    

    system("pause");
    return 0;
}