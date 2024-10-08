#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+5;
int arr[maxN], x[maxN], y[maxN], dp[maxN];

int dis(int x1, int y1, int x2, int y2) {
    return abs(x1-x2)+abs(y1-y2);
}

int main()
{   
    int n{}, m{};
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i] >> x[i] >> y[i];
    }

    int ans{};
    for (int i = 1; i <= m; i++)
    {
        dp[i] = 1;  //×¢Òâ³õÊ¼»¯
        for (int j = 1; j < i; j++)
        {
            if (dis(x[i],y[i],x[j],y[j]) <= arr[i]-arr[j]) {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    
    cout << ans << endl;

    system("pause");
    return 0;
}