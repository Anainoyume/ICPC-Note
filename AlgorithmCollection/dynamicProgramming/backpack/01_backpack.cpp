//��׼��01����
#include <bits/stdc++.h>
using namespace std;

int C, n;
int c[10001], w[10001]; //c��ʾ���, w�Ǽ�ֵ
int dp[10001][10001];

int main()
{
    cin >> C >> n;  //CΪ����������nΪ��Ʒ����

    for (int i = 1; i <= n; i++)
        cin >> c[i] >> w[i];
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            if (c[i] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-c[i]]+w[i]);
                //�����ǰ�������Էŵ���
                /* 
                    1. ����
                    ���ž��� dp[i-1][j]
                    2. ��
                    dp[i-1][j-c[i]]+w[i]
                    ��ʾ���Ȼ�ȡǰ i-1 ����Ʒ��������Ϊ j-c[i]  ���������ŵ�����ֵ��
                    �ټ��ϵ�ǰ�����Ʒ�ļ�ֵ
                    
                    ���ǽ�����ȡ���ֵ
                 */
        }
    }
    
    cout << dp[n][C] << endl;

    system("pause");
    return 0;
}