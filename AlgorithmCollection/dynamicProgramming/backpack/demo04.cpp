#include <bits/stdc++.h>
using namespace std;

const int md = 1e6+7;
int n, m;
int dp[105][105], cnt[105];
//dp[i][j]��ʾǰi����Ʒǡ�ôճ�jԪ�������

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        dp[i][0] = 1;
    }
    dp[0][0] = 1;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] += dp[i-1][j] % md;    //ע�ⲻѡ�����ֻ����һ��
            for (int k = 1; k <= cnt[i]; k++)
            {
                if (j >= k) dp[i][j] += dp[i-1][j-k] % md;
            }
        } 
    }
    
    cout << dp[n][m] % md << endl;

    system("pause");
    return 0;
}
