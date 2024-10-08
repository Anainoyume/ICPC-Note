#include <bits/stdc++.h>
using namespace std;

const int maxN = 10;
int mp[maxN][maxN];
int dp[maxN][maxN][maxN][maxN];
/* 
    方格取数问题，双线程dp
 */
int main()
{
    int n{};
    cin >> n;

    int x{}, y{}, value{};
    while (true)
    {
        cin >> x >> y >> value;
        if (x == 0 && y == 0 && value == 0)
            break;
        mp[x][y] = value;
    }

    for (int x1 = 1; x1 <= n; x1++)
    {
        for (int y1 = 1; y1 <= n; y1++)
        {
            for (int x2 = 1; x2 <= n; x2++)
            {
                for (int y2 = 1; y2 <= n; y2++)
                {
                    int m1 = max(dp[x1 - 1][y1][x2 - 1][y2],dp[x1 - 1][y1][x2][y2 - 1]);
                    int m2 = max(dp[x1][y1 - 1][x2 - 1][y2],dp[x1][y1 - 1][x2][y2 - 1]);
                    dp[x1][y1][x2][y2] = max(m1,m2) + mp[x1][y1];
                    if (x1 != x2 && y1 != y2) dp[x1][y1][x2][y2] += mp[x2][y2];
                }
            }
        }
    }

    cout << dp[n][n][n][n] << endl;

    system("pause");
    return 0;
}