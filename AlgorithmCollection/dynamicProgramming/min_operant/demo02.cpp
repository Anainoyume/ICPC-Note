#include <bits/stdc++.h>
using namespace std;

const int maxN = 2005;
int dp[maxN][maxN];

int main(int argc, char const *argv[])
{
    string A{}, B{};
    cin >> A >> B;

    int lenA = A.size(), lenB = B.size();

    //Don't forget to initialize.
    for (int i = 0; i <= lenA; i++)
        dp[i][0] = i;
    
    for (int i = 0; i <= lenB; i++)
        dp[0][i] = i;

    for (int i = 1; i <= lenA; i++)
    {
        for (int j = 1; j <= lenB; j++)
        {
            if (A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1]);
            }
        }
    }
    
    cout << dp[lenA][lenB] << endl;

    system("pause");
    return 0;
}
