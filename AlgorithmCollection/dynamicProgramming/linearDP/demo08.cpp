#include <bits/stdc++.h>
using namespace std;

#define IOS cin.tie(0)->sync_with_stdio(false)

const int md = 1e9+7;
const int maxN = 1005;

int m;
int lenA, lenB;

int dp[maxN][205][2];

int main(int argc, char const *argv[])
{
    IOS;

    cin >> lenA >> lenB >> m;
    char a[lenA+1], b[lenB+1];
    scanf("%s %s",a+1,b+1);
    
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= lenA; i++)
    {
        for (int j = lenB; j >= 1; j--)
        {
            for (int k = 1; k <= m; k++)
            {
                dp[j][k][0] = (dp[j][k][0] + dp[j][k][1]) % md; //这一行要先遇到上一行的数据，因此先放前面
                if (a[i] == b[j]) {
                    dp[j][k][1] = (dp[j-1][k][1] + dp[j-1][k-1][1] + dp[j-1][k-1][0]) % md;
                }
                else {
                    dp[j][k][1] = 0;
                }
            }
        }
    }
    
    cout << (dp[lenB][m][1]+dp[lenB][m][0]) % md << endl;
    
    
    system("pause");
    return 0;
}
