//���ر��� ʱ���Ż�+�ռ��Ż�
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c��ʾ���, w�Ǽ�ֵ
int dp[10001][10001];

int main()
{
    cin >> C >> n;  //CΪ����������nΪ��Ʒ������ÿ����Ʒ�����޸�

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            if (j - c[i] >= 0)
                dp[i][j] = max(dp[i-1][j],dp[i][j-c[i]]+w[i]);  //ʽ�ӿ����Ƶ�
            else 
                dp[i][j] = dp[i-1][j];
            /* 
                �������ǳ���������ʽ��
                dp[i][j] ��ʾ������ѡ����Ʒ���õ������ֵ

                dp[i][j] = dp[i][j-c[i]]+w[i] �ĺ�����ǵ�i����Ʒһֱѡ��

                �� dp[i][j] = dp[i-1][j] �ĺ������ǣ��̳���һ�����ѡ�����Ʒ


             */
        }
    }
    
    cout << dp[n][C] << endl;

    system("pause");
    return 0;
}