#include <bits/stdc++.h>
using namespace std;

const int maxN = 100+5;
int n,m;
int g[maxN][maxN];
int dp[maxN][maxN];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int ans;
/* 
    �м��仯����һ����DP�����仯��������DP��һ����ʽ
    �����������Զ������Ƶ�DP����DP���Ե����ϵ��ơ�

    �������ھ�������DP��⡣

    ����Լ30���ӵĳ��ԣ������ǲ�����˫��forѭ����dp��
    dfs�ж�������չ����ʵ�������Ǹ������ټ����ߵĵ㡣

    ������Ե����Ͻ���dp�����Բ�ȡbfs��չ��ÿ������չ��ȥ��
    �������ͷ���������ֱ��дһ�� dfs �ˡ�

    �������ǻ��ǲ�ȡ���仯����

 */
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            dp[i][j] = 1;
        }
    
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         for (int k = 0; k < 4; k++)
    //         {
    //             int tx = i+dx[k];
    //             int ty = j+dy[k];
    //             if (tx <= 0 || tx > n || ty <= 0 || ty > m) continue;
    //             if (g[tx][ty] > g[i][j])
    //                 dp[tx][ty] = max(dp[i][j]+1,dp[tx][ty]);
    //         }
    //     }
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    cout << ans << endl;


    system("pause");
    return 0;
}