#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e4+5;
int n, l[maxN], r[maxN], dp[maxN][2];

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    
    int ans{};
    //我们设计 dp[i][0] 为第i层到达左侧的最短步数
    //        dp[i][1] 为第i层到达右侧的最短步数
    dp[1][0] = r[1]-1+(r[1]-l[1]);
    dp[1][1] = r[1]-1;

    for (int i = 2; i <= n; i++)
    {
        //到达这一层的左侧，就要从上一层先到右边，再到左边
        dp[i][0] = min(abs(r[i]-l[i-1])+dp[i-1][0],abs(r[i]-r[i-1])+dp[i-1][1])+(r[i]-l[i])+1;
        //到达这一层的右侧，就要从上一层先到左边，再到右边
        dp[i][1] = min(abs(l[i]-l[i-1])+dp[i-1][0],abs(l[i]-r[i-1])+dp[i-1][1])+(r[i]-l[i])+1;
    }
    
    cout << min(abs(n-l[n])+dp[n][0],abs(n-r[n])+dp[n][1]) << endl;
    
    system("pause");
    return 0;
}
