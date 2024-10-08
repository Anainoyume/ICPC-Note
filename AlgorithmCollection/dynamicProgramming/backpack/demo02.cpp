#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n{}, v{};
    cin >> v >> n;
    int dp[v+1]{};
    int c[n+1];

    for (int i = 1; i <= n; i++)
        cin >> c[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = v; j >= c[i]; j--)
        {
            dp[j] = max(dp[j],dp[j-c[i]]+c[i]);
        }
    }
    
    cout << v-dp[v] << endl;

    system("pause");
    return 0;
}