#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e3+5;
const int v = 2e4;
const int md = 998244353;
int n, ans;
int h[maxN];
int dp[maxN][2*v+1];    // dp[i][j] ��ʾ������i��β��jΪ����ĵȲ����и���

int main(int argc, char const *argv[])
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    
    fill(dp[0],dp[0]+maxN*(2*v+1),1);
    for (int i = 1; i <= n; i++)
    {
        ans++;
        for (int j = 1; j < i; j++)
        {
            dp[i][h[i]-h[j]+v] += (dp[j][h[i]-h[j]+v]) % md;
            dp[i][h[i]-h[j]+v] %= md;
            ans += (dp[j][h[i]-h[j]+v]) % md;
            ans %= md;  //ע��ȡģ����
        }
    }
    
    cout << ans % md << endl;
    
    system("pause");
    return 0;
}
